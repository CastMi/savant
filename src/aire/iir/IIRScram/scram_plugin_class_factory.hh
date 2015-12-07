#ifndef SCRAM_PLUGIN_CLASS_FACTORY_HH
#define SCRAM_PLUGIN_CLASS_FACTORY_HH

// Copyright (c) Clifton Labs, Inc.  All rights reserved.

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

#include "savant_config.hh"
#include "plugin_class_factory.hh"
/** IIRScram implementation of the plugin class factory.  This isn't strictly
    necessary, but large portions of the code base have been refactored to work
    independent of the type of nodes they generate.  Thus IIRScram has become a
    special case of the general plugin methodology, requiring it's own class factory. */
class scram_plugin_class_factory : public plugin_class_factory {
public:
  IIRRef get_new_class(IIR_Kind);

  // Various plugin related classes
  StandardPackageRef                               get_standard_package();

  // Class return methods
  IIR_AboveAttributeRef                            new_IIR_AboveAttribute();
  IIR_AbsoluteOperatorRef                          new_IIR_AbsoluteOperator();
  IIR_AccessSubtypeDefinitionRef                   new_IIR_AccessSubtypeDefinition();
  IIR_AccessTypeDefinitionRef                      new_IIR_AccessTypeDefinition();
  IIR_AcrossAttributeRef                           new_IIR_AcrossAttribute();
  IIR_ActiveAttributeRef                           new_IIR_ActiveAttribute();
  IIR_AdditionOperatorRef                          new_IIR_AdditionOperator();
  IIR_AggregateRef                                 new_IIR_Aggregate();
  IIR_AliasDeclarationRef                          new_IIR_AliasDeclaration();
  IIR_AllocatorRef                                 new_IIR_Allocator();
  IIR_AndOperatorRef                               new_IIR_AndOperator();
  IIR_ArchitectureDeclarationRef                   new_IIR_ArchitectureDeclaration();
  IIR_ArchitectureStatementRef                     new_IIR_ArchitectureStatement();
  IIR_ArchitectureStatementListRef                 new_IIR_ArchitectureStatementList();
  IIR_ArrayNatureDefinitionRef                     new_IIR_ArrayNatureDefinition();
  IIR_ArraySubnatureDefinitionRef                  new_IIR_ArraySubnatureDefinition();
  IIR_ArraySubtypeDefinitionRef                    new_IIR_ArraySubtypeDefinition();
  IIR_ArrayTypeDefinitionRef new_IIR_ArrayTypeDefinition();
  IIR_AscendingAttributeRef new_IIR_AscendingAttribute();
  IIR_AssertionStatementRef new_IIR_AssertionStatement();
  IIR_AssociationElementByExpressionRef new_IIR_AssociationElementByExpression();
  IIR_AssociationElementOpenRef new_IIR_AssociationElementOpen();
  IIR_AssociationListRef new_IIR_AssociationList();
  IIR_AttributeDeclarationRef new_IIR_AttributeDeclaration();
  IIR_AttributeSpecificationRef new_IIR_AttributeSpecification();
  IIR_AttributeSpecificationListRef new_IIR_AttributeSpecificationList();
  IIR_BaseAttributeRef new_IIR_BaseAttribute();
  IIR_BitStringLiteralRef new_IIR_BitStringLiteral();
  IIR_BlockConfigurationRef new_IIR_BlockConfiguration();
  IIR_BlockStatementRef new_IIR_BlockStatement();
  IIR_BranchQuantityDeclarationRef new_IIR_BranchQuantityDeclaration();
  IIR_BreakElementRef new_IIR_BreakElement();
  IIR_BreakStatementRef new_IIR_BreakStatement();
  IIR_CaseStatementAlternativeByChoicesRef new_IIR_CaseStatementAlternativeByChoices();
  IIR_CaseStatementAlternativeByExpressionRef new_IIR_CaseStatementAlternativeByExpression();
  IIR_CaseStatementAlternativeByOthersRef new_IIR_CaseStatementAlternativeByOthers();
  IIR_CaseStatementAlternativeListRef new_IIR_CaseStatementAlternativeList();
  IIR_CaseStatementRef new_IIR_CaseStatement();
  IIR_CharacterLiteralRef new_IIR_CharacterLiteral();
  IIR_ChoiceRef new_IIR_Choice();
  IIR_ChoiceListRef new_IIR_ChoiceList();
  IIR_CommentRef new_IIR_Comment();
  IIR_CommentListRef new_IIR_CommentList();
  IIR_ComponentConfigurationRef new_IIR_ComponentConfiguration();
  IIR_ComponentDeclarationRef new_IIR_ComponentDeclaration();
  IIR_ComponentInstantiationStatementRef new_IIR_ComponentInstantiationStatement();
  IIR_ConcatenationOperatorRef new_IIR_ConcatenationOperator();
  IIR_ConcurrentAssertionStatementRef new_IIR_ConcurrentAssertionStatement();
  IIR_ConcurrentBreakStatementRef new_IIR_ConcurrentBreakStatement();
  IIR_ConcurrentConditionalSignalAssignmentRef new_IIR_ConcurrentConditionalSignalAssignment();
  IIR_ConcurrentGenerateForStatementRef new_IIR_ConcurrentGenerateForStatement();
  IIR_ConcurrentGenerateIfStatementRef new_IIR_ConcurrentGenerateIfStatement();
  IIR_ConcurrentProcedureCallStatementRef new_IIR_ConcurrentProcedureCallStatement();
  IIR_ConcurrentSelectedSignalAssignmentRef new_IIR_ConcurrentSelectedSignalAssignment();
  IIR_ConditionalWaveformRef new_IIR_ConditionalWaveform();
  IIR_ConditionalWaveformListRef new_IIR_ConditionalWaveformList();
  IIR_ConfigurationDeclarationRef new_IIR_ConfigurationDeclaration();
  IIR_ConfigurationItemRef new_IIR_ConfigurationItem();
  IIR_ConfigurationItemListRef new_IIR_ConfigurationItemList();
  IIR_ConfigurationSpecificationRef new_IIR_ConfigurationSpecification();
  IIR_ContributionAttributeRef new_IIR_ContributionAttribute();
  IIR_ConstantDeclarationRef new_IIR_ConstantDeclaration();
  IIR_ConstantInterfaceDeclarationRef new_IIR_ConstantInterfaceDeclaration();
  IIR_DeclarationListRef new_IIR_DeclarationList();
  IIR_DelayedAttributeRef new_IIR_DelayedAttribute();
  IIR_DesignatorByAllRef new_IIR_DesignatorByAll();
  IIR_DesignatorByOthersRef new_IIR_DesignatorByOthers();
  IIR_DesignatorExplicitRef new_IIR_DesignatorExplicit();
  IIR_DesignatorRef new_IIR_Designator();
  IIR_DesignatorListRef new_IIR_DesignatorList();
  IIR_DesignFileRef new_IIR_DesignFile();
  IIR_DesignFileListRef new_IIR_DesignFileList();
  IIR_DesignUnitListRef new_IIR_DesignUnitList();
  IIR_DisconnectSpecificationRef new_IIR_DisconnectSpecification();
  IIR_DivisionOperatorRef new_IIR_DivisionOperator();
  IIR_DotAttributeRef new_IIR_DotAttribute();
  IIR_DrivingAttributeRef new_IIR_DrivingAttribute();
  IIR_DrivingValueAttributeRef new_IIR_DrivingValueAttribute();
  IIR_ElementDeclarationRef new_IIR_ElementDeclaration();
  IIR_ElementDeclarationListRef new_IIR_ElementDeclarationList();
  IIR_ElsifRef new_IIR_Elsif();
  IIR_EntityClassEntryRef new_IIR_EntityClassEntry();
  IIR_EntityClassEntryListRef new_IIR_EntityClassEntryList();
  IIR_EntityDeclarationRef new_IIR_EntityDeclaration();
  IIR_EntityNameListRef new_IIR_EntityNameList();
  IIR_EnumerationLiteralRef new_IIR_EnumerationLiteral();
  IIR_EnumerationLiteralListRef new_IIR_EnumerationLiteralList();
  IIR_EnumerationSubtypeDefinitionRef new_IIR_EnumerationSubtypeDefinition();
  IIR_EnumerationTypeDefinitionRef new_IIR_EnumerationTypeDefinition();
  IIR_EqualityOperatorRef new_IIR_EqualityOperator();
  IIR_EventAttributeRef new_IIR_EventAttribute();
  IIR_ExitStatementRef new_IIR_ExitStatement();
  IIR_ExponentiationOperatorRef new_IIR_ExponentiationOperator();
  IIR_FileDeclarationRef new_IIR_FileDeclaration();
  IIR_FileInterfaceDeclarationRef new_IIR_FileInterfaceDeclaration();
  IIR_FileTypeDefinitionRef new_IIR_FileTypeDefinition();
  IIR_FloatingPointLiteral32Ref new_IIR_FloatingPointLiteral32();
  IIR_FloatingPointLiteral64Ref new_IIR_FloatingPointLiteral64();
  IIR_FloatingPointLiteralRef new_IIR_FloatingPointLiteral();
  IIR_FloatingSubtypeDefinitionRef new_IIR_FloatingSubtypeDefinition();
  IIR_FloatingTypeDefinitionRef new_IIR_FloatingTypeDefinition();
  IIR_ForLoopStatementRef new_IIR_ForLoopStatement();
  IIR_FreeQuantityDeclarationRef new_IIR_FreeQuantityDeclaration();
  IIR_FunctionCallRef new_IIR_FunctionCall();
  IIR_FunctionDeclarationRef new_IIR_FunctionDeclaration();
  IIR_GenericListRef new_IIR_GenericList();
  IIR_GreaterThanOperatorRef new_IIR_GreaterThanOperator();
  IIR_GreaterThanOrEqualOperatorRef new_IIR_GreaterThanOrEqualOperator();
  IIR_GroupConstituentRef new_IIR_GroupConstituent();
  IIR_GroupDeclarationRef new_IIR_GroupDeclaration();
  IIR_GroupTemplateDeclarationRef new_IIR_GroupTemplateDeclaration();
  IIR_HighAttributeRef new_IIR_HighAttribute();
  IIR_IdentifierRef new_IIR_Identifier();
  IIR_IdentifierListRef new_IIR_IdentifierList();
  IIR_IdentityOperatorRef new_IIR_IdentityOperator();
  IIR_IfStatementRef new_IIR_IfStatement();
  IIR_ImageAttributeRef new_IIR_ImageAttribute();
  IIR_IncompleteTypeDefinitionRef new_IIR_IncompleteTypeDefinition();
  IIR_IndexedNameRef new_IIR_IndexedName();
  IIR_InequalityOperatorRef new_IIR_InequalityOperator();
  IIR_InstanceNameAttributeRef new_IIR_InstanceNameAttribute();
  IIR_IntegerLiteral32Ref new_IIR_IntegerLiteral32();
  IIR_IntegerLiteral64                         Ref new_IIR_IntegerLiteral64();
  IIR_IntegerLiteral                           Ref new_IIR_IntegerLiteral();
  IIR_IntegerSubtypeDefinition                 Ref new_IIR_IntegerSubtypeDefinition();
  IIR_IntegerTypeDefinition                    Ref new_IIR_IntegerTypeDefinition();
  IIR_InterfaceList                            Ref new_IIR_InterfaceList();
  IIR_Label                                    Ref new_IIR_Label();
  IIR_LastActiveAttribute                      Ref new_IIR_LastActiveAttribute();
  IIR_LastEventAttribute                       Ref new_IIR_LastEventAttribute();
  IIR_LastValueAttribute                       Ref new_IIR_LastValueAttribute();
  IIR_LeftAttribute                            Ref new_IIR_LeftAttribute();
  IIR_LeftOfAttribute                          Ref new_IIR_LeftOfAttribute();
  IIR_LengthAttribute                          Ref new_IIR_LengthAttribute();
  IIR_LessThanOperator                         Ref new_IIR_LessThanOperator();
  IIR_LessThanOrEqualOperator                  Ref new_IIR_LessThanOrEqualOperator();
  IIR_LibraryClause                            Ref new_IIR_LibraryClause();
  IIR_LibraryDeclaration                       Ref new_IIR_LibraryDeclaration();
  IIR_LibraryUnitList                          Ref new_IIR_LibraryUnitList();
  IIR_Literal                                  Ref new_IIR_Literal();
  IIR_LTFAttribute                             Ref new_IIR_LTFAttribute();
  IIR_LowAttribute                             Ref new_IIR_LowAttribute();
  IIR_ModulusOperator                          Ref new_IIR_ModulusOperator();
  IIR_MultiplicationOperator                   Ref new_IIR_MultiplicationOperator();
  IIR_Name                                     Ref new_IIR_Name();
  IIR_NameList                                 Ref new_IIR_NameList();
  IIR_NandOperator                             Ref new_IIR_NandOperator();
  IIR_NatureDeclaration                        Ref new_IIR_NatureDeclaration();
  IIR_NatureDefinition                         Ref new_IIR_NatureDefinition();
  IIR_NegationOperator                         Ref new_IIR_NegationOperator();
  IIR_NextStatement                            Ref new_IIR_NextStatement();
  IIR_NorOperator                              Ref new_IIR_NorOperator();
  IIR_NotOperator                              Ref new_IIR_NotOperator();
  IIR_NullStatement                            Ref new_IIR_NullStatement();
  IIR_OrOperator                               Ref new_IIR_OrOperator();
  IIR_OthersInitialization                     Ref new_IIR_OthersInitialization();
  IIR_PackageBodyDeclaration                   Ref new_IIR_PackageBodyDeclaration();
  IIR_PackageDeclaration                       Ref new_IIR_PackageDeclaration();
  IIR_PathNameAttribute                        Ref new_IIR_PathNameAttribute();
  IIR_PhysicalLiteral                          Ref new_IIR_PhysicalLiteral();
  IIR_PhysicalSubtypeDefinition                Ref new_IIR_PhysicalSubtypeDefinition();
  IIR_PhysicalTypeDefinition                   Ref new_IIR_PhysicalTypeDefinition();
  IIR_PhysicalUnit                             Ref new_IIR_PhysicalUnit();
  IIR_PortList                                 Ref new_IIR_PortList();
  IIR_PosAttribute                             Ref new_IIR_PosAttribute();
  IIR_PredAttribute                            Ref new_IIR_PredAttribute();
  IIR_ProcedureCallStatement                   Ref new_IIR_ProcedureCallStatement();
  IIR_ProcedureDeclaration                     Ref new_IIR_ProcedureDeclaration();
  IIR_ProcessStatement                         Ref new_IIR_ProcessStatement();
  IIR_QualifiedExpression                      Ref new_IIR_QualifiedExpression();
  IIR_QuantityDeclaration                      Ref new_IIR_QuantityDeclaration();
  IIR_QuietAttribute                           Ref new_IIR_QuietAttribute();
  IIR_RangeAttribute                           Ref new_IIR_RangeAttribute();
  IIR_RangeTypeDefinition                      Ref new_IIR_RangeTypeDefinition();
  IIR_RecordTypeDefinition                     Ref new_IIR_RecordTypeDefinition();
  IIR_ReferenceAttribute                       Ref new_IIR_ReferenceAttribute();
  IIR_RemainderOperator                        Ref new_IIR_RemainderOperator();
  IIR_ReportStatement                          Ref new_IIR_ReportStatement();
  IIR_ReturnStatement                          Ref new_IIR_ReturnStatement();
  IIR_ReverseRangeAttribute                    Ref new_IIR_ReverseRangeAttribute();
  IIR_RightAttribute                           Ref new_IIR_RightAttribute();
  IIR_RightOfAttribute                         Ref new_IIR_RightOfAttribute();
  IIR_ROLOperator                              Ref new_IIR_ROLOperator();
  IIR_ROROperator                              Ref new_IIR_ROROperator();
  IIR_ScalarNatureDefinition                   Ref new_IIR_ScalarNatureDefinition();
  IIR_SelectedNameByAll                        Ref new_IIR_SelectedNameByAll();
  IIR_SelectedName                             Ref new_IIR_SelectedName();
  IIR_SelectedWaveform                         Ref new_IIR_SelectedWaveform();
  IIR_SelectedWaveformList                     Ref new_IIR_SelectedWaveformList();
  IIR_SensitizedProcessStatement               Ref new_IIR_SensitizedProcessStatement();
  IIR_SequentialStatementList                  Ref new_IIR_SequentialStatementList();
  IIR_SharedVariableDeclaration                Ref new_IIR_SharedVariableDeclaration();
  IIR_SignalAssignmentStatement                Ref new_IIR_SignalAssignmentStatement();
  IIR_SignalDeclaration                        Ref new_IIR_SignalDeclaration();
  IIR_SignalInterfaceDeclaration               Ref new_IIR_SignalInterfaceDeclaration();
  IIR_Signature                                Ref new_IIR_Signature();
  IIR_SimpleNameAttribute                      Ref new_IIR_SimpleNameAttribute();
  IIR_SimpleName                               Ref new_IIR_SimpleName();
  IIR_SimpleSimultaneousStatement              Ref new_IIR_SimpleSimultaneousStatement();
  IIR_SimultaneousElsif                        Ref new_IIR_SimultaneousElsif();
  IIR_SimultaneousIfStatement                  Ref new_IIR_SimultaneousIfStatement();
  IIR_SLAOperator                              Ref new_IIR_SLAOperator();
  IIR_SliceName                                Ref new_IIR_SliceName();
  IIR_SLLOperator                              Ref new_IIR_SLLOperator();
  IIR_SourceQuantityDeclaration                Ref new_IIR_SourceQuantityDeclaration();
  IIR_SRAOperator                              Ref new_IIR_SRAOperator();
  IIR_SRLOperator                              Ref new_IIR_SRLOperator();
  IIR_StableAttribute                          Ref new_IIR_StableAttribute();
  IIR_StringLiteral                            Ref new_IIR_StringLiteral();
  IIR_SubprogramDeclaration                    Ref new_IIR_SubprogramDeclaration();
  IIR_SubtractionOperator                      Ref new_IIR_SubtractionOperator();
  IIR_SubtypeDeclaration                       Ref new_IIR_SubtypeDeclaration();
  IIR_SuccAttribute                            Ref new_IIR_SuccAttribute();
  IIR_TerminalDeclaration                      Ref new_IIR_TerminalDeclaration();
  IIR_TerminalInterfaceDeclaration             Ref new_IIR_TerminalInterfaceDeclaration();
  IIR_TextLiteral                              Ref new_IIR_TextLiteral();
  IIR_ThroughAttribute                         Ref new_IIR_ThroughAttribute();
  IIR_TransactionAttribute                     Ref new_IIR_TransactionAttribute();
  IIR_Tuple                                    Ref new_IIR_Tuple();
  IIR_TypeConversion                           Ref new_IIR_TypeConversion();
  IIR_TypeDeclaration                          Ref new_IIR_TypeDeclaration();
  IIR_UnitList                                 Ref new_IIR_UnitList();
  IIR_UseClause                                Ref new_IIR_UseClause();
  IIR_UserAttribute                            Ref new_IIR_UserAttribute();
  IIR_ValAttribute                             Ref new_IIR_ValAttribute();
  IIR_ValueAttribute                           Ref new_IIR_ValueAttribute();
  IIR_VariableAssignmentStatement              Ref new_IIR_VariableAssignmentStatement();
  IIR_VariableDeclaration                      Ref new_IIR_VariableDeclaration();
  IIR_VariableInterfaceDeclaration             Ref new_IIR_VariableInterfaceDeclaration();
  IIR_WaitStatement                            Ref new_IIR_WaitStatement();
  IIR_WaveformElement                          Ref new_IIR_WaveformElement();
  IIR_WaveformList                             Ref new_IIR_WaveformList();
  IIR_WhileLoopStatement                       Ref new_IIR_WhileLoopStatement();
  IIR_XnorOperator                             Ref new_IIR_XnorOperator();
  IIR_XorOperator                              Ref new_IIR_XorOperator();
  IIR_ZTFAttribute                             Ref new_IIR_ZTFAttribute();

  /** Access the singleton. */
  static plugin_class_factoryRef instance();

private:
  StandardPackageRef new_StandardPackage();

  scram_plugin_class_factory(){}
  virtual ~scram_plugin_class_factory(){}
};
#endif
