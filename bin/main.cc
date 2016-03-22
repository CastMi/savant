// Copyright (c) 1995-2003 The University of Cincinnati.
// Copyright CERN 2015-2016 Michele Castellana <michele.castellana@cern.ch>.
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey    philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com
//          Timothy J. McBrayer
//          Narayanan Thondugulam
//          Magnus Danielson      cfmd@swipnet.se

#include "savant_config.hh"
#include <signal.h>
#include "savant.hh"
#include "scram.hh"
#include "version.hh"
#include "IIR_DesignFile.hh"
#include "IIRScram_DesignFileList.hh"
#include "IIR_LibraryUnit.hh"
#include "IIR_EntityDeclaration.hh"
#include "IIR_ArchitectureDeclaration.hh"
#include "IIRScram_ConfigurationSpecification.hh"
#include "IIRScram_ComponentInstantiationStatement.hh"
#include "IIRScram_ComponentDeclaration.hh"
#include "symbol_table.hh"
#include "dl_list.hh"
#include "IIR_EnumerationLiteral.hh"
#include "IIR_Identifier.hh"
#include "language_processing_control.hh"
#include <cctype>
#include <fstream>
#include "ArgumentParser.hpp"
#include "StandardPackage.hh"
#include "verilogParserDriver.hpp"

#include "IIRScram_DesignFile.hh"
#include "scram_plugin_class_factory.hh"
#include "ScramStandardPackage.hh"

// Library/Plugin stuff
#include <ltdl.h>
#include <PluginManager.h>
#include <PluginBase.h>
#include "plugin_interface.hh"
#include "consistency.hpp"

// to invoke the library manager
#include "library_manager.hh"

// for library manager
extern string design_library_name;

extern bool parse_error;
extern bool verbose_output;

#if defined(__GNUG__)
#define IOS_BIN ios::bin
#else
#define IOS_BIN ios::binary
#endif

int
main (int argc, char *argv[]) {
   ArgumentParser ap;
   switch( ap.vectorifyArguments( argc, argv ) ) {
      case EXIT_OK:
         return EXIT_SUCCESS;
         break;
      case CONTINUE_OK:
         break;
      case ERROR:
         return EXIT_FAILURE;
      default:
         std::cerr << "The argument parser returned a weird value" << std::endl;
         return EXIT_FAILURE;
   }

   IIR_DesignFileList *iir_verilog_design_files_processed = NULL;
   IIR_DesignFileList *iir_vhdl_design_files_processed = NULL;

   library_manager::instance()->init_std_library(ScramStandardPackage::instance());

   ASSERT( !design_library_name.empty() );

   if( verbose_output )
      std::cerr << "Start the frontend part" << std::endl;

   if(ap.getVHDLFiles().size() > 0) {
      /* Create VHDL IR */
      scram parser( true, design_library_name,
            scram_plugin_class_factory::instance(),
            ScramStandardPackage::instance() );
      iir_vhdl_design_files_processed = parser.parse_files( ap.getVHDLFiles() );  

      if( parse_error == FALSE ){
         cerr << "VHDL parse complete - no errors." << endl;
      }
      else{
         return EXIT_FAILURE;
      }
   }

   if(ap.getVerilogFiles().size() > 0) {
      if( verbose_output )
         std::cerr << "Finish VHDL frontend and starting Verilog frontend" << std::endl;

      /* create verilog IR */
      VeriParser parser( design_library_name, scram_plugin_class_factory::instance(), ScramStandardPackage::instance() );
      iir_verilog_design_files_processed = parser.parse_verilog( ap.getVerilogFiles() );
      cerr << "Verilog parse complete - no errors." << endl;
   }

   if( verbose_output )
      std::cerr << "Finish the frontend part" << std::endl;

   // connect trees
   for(auto it = consistency::instance()->get_missing().begin();
         it != consistency::instance()->get_missing().end();
         it++) {
      dynamic_cast<IIRScram_ComponentInstantiationStatement*>(*it)->_type_check_instantiated_unit();
      ASSERT(dynamic_cast<IIRScram_ComponentDeclaration*>(dynamic_cast<IIRScram_ComponentInstantiationStatement*>(*it)->get_instantiated_unit())->_get_entity() == NULL);
   }

   if( verbose_output )
      std::cerr << "Finish to connect trees" << std::endl;

   if(iir_verilog_design_files_processed != NULL && iir_vhdl_design_files_processed == NULL) {
      iir_vhdl_design_files_processed = iir_verilog_design_files_processed;
   } else if(iir_verilog_design_files_processed != NULL && iir_vhdl_design_files_processed != NULL) {
      // FIXME: should become something easier like:
      // iir_vhdl_design_files_processed->append(iir_verilog_design_files_processed);
      IIR_DesignFile *tmp = dynamic_cast<IIR_DesignFile *>(iir_verilog_design_files_processed->first());
      while( tmp != NULL ){
         iir_vhdl_design_files_processed->append(tmp);
         tmp = dynamic_cast<IIR_DesignFile *>(iir_vhdl_design_files_processed->successor( tmp ));
      }
   } else if(iir_verilog_design_files_processed == NULL && iir_vhdl_design_files_processed == NULL) {
      cerr << "Something went wrong." << endl;
      return EXIT_FAILURE;
   }

   if( iir_vhdl_design_files_processed != NULL ) {
      char *plugin_dir = getenv( "SAVANT_PLUGIN_PATH" );
      if (plugin_dir != NULL)
         PluginManager::instance()->addSearchDir(plugin_dir);

      // First add the name of the publish cc/tyvis to list as a special case
      list<string>        plugin_names;
      if (ap.getPublishCC() == true)
         plugin_names.push_back("libtyvisplugin.la");

      // Now we'll walk the list, and process the tree for VHDL
      if (ap.getPublishHDL() == true) {
         IIR *to_publish = iir_vhdl_design_files_processed->first();
         while( to_publish != NULL ){
            ASSERT( dynamic_cast<IIR_DesignFile *>( to_publish ) );
            to_publish->publish_vhdl( cout );
            cout.flush();
            to_publish =
               iir_vhdl_design_files_processed->successor( dynamic_cast<IIR_DesignFile *>(to_publish) );
         }
      }

      for (list<string>::iterator iter = plugin_names.begin(); iter != plugin_names.end(); ++iter) {
         PluginBase *module = PluginManager::instance()->loadPlugin(*iter);
         if ( !module ) {
            cout << "Error: " << PluginManager::instance()->getLastError() << endl;
            return EXIT_FAILURE;
         }

         // Just got a module pointer, cast it over to our interface
         // Initialize the library module manager to search for the plugin in the plugins directory
         plugin_interface *plugin = dynamic_cast<plugin_interface *>(module);

         // Now we'll walk the list, and process the tree(s) for plugins
         IIR_DesignFile *to_publish = dynamic_cast<IIR_DesignFile *>(iir_vhdl_design_files_processed->first());
         while( to_publish != NULL ){
            if ((ap.getPublishCC() == true) && (iter == plugin_names.begin())){
               cerr << "Starting C++ code generation..." << endl;
               char last_unit = false;
               if( iir_vhdl_design_files_processed->successor( to_publish ) == NULL ){
                  last_unit = true;
               }
               char **arg_list = new char *;
               arg_list[0] = new char[10];
               arg_list[0] = &last_unit;
               plugin->process_tree(to_publish, 1, arg_list);
               cerr << "Code generation finished." << endl;
            } else {
               // Normal plugin
               cerr << "Starting plugin " << *iter << endl;
               plugin->process_tree(to_publish, 0, NULL);
               cerr << "Plugin processing completed." << endl;
            }

            to_publish = dynamic_cast<IIR_DesignFile *>(iir_vhdl_design_files_processed->successor( to_publish ));
         }

         PluginManager::instance()->unloadPlugin(*iter);
      }
   } else {
      cerr << "Something went wrong." << endl;
      return EXIT_FAILURE;
   }

   return 0;
}

