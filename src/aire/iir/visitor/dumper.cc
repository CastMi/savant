/*
 * Copyright (C) 2016 Michele Castellana <blacklion727@gmail.com>
 * 
 * This source code is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This source code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

DumperVisitor::DumperVisitor() {};
DumperVisitor::~DumperVisitor() {};

bool
DumperVisitor::visit(IIR_AbsoluteOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AccessSubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AccessTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ActiveAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AdditionOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Aggregate * item, visitor_argument_type * ) {
  os << "(";
  os << dynamic_cast<IIRBase_AssociationList *>(item->get_element_association_list());
  os << ")";

  return true;
}

bool
DumperVisitor::visit(IIR_AliasDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Allocator * item, visitor_argument_type * ) {
  os << "new ";
  os << *item->get_type_mark();
  
  return true;
}

bool
DumperVisitor::visit(IIR_AndOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ArchitectureDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ArchitectureStatementList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ArraySubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ArrayTypeDefinition * item, visitor_argument_type * ) {
  os << "array ( " << *item->get_resolved_index_subtype(); 
  
  IIR_TypeDefinition *element_type = item->get_element_subtype();
  
  while( element_type->is_array_type() && element_type->is_anonymous() ){
    os << ", " << *(element_type->get_resolved_index_subtype());
    element_type = element_type->get_element_subtype();
  }
  
  os << " ) of " << *(element_type->get_declarator());
  
  return true;
}

bool
DumperVisitor::visit(IIR_AscendingAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AssertionStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AssociationElementByExpression *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AssociationElementOpen *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AssociationList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AttributeDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AttributeSpecification *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_AttributeSpecificationList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_BaseAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_BitStringLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_BlockConfiguration * item, visitor_argument_type * ) {
  if( item->get_block_specification() ){
    os << *item->get_block_specification();
  }
  else{
    os << "<ANONYMOUS>";
  }

  return true;
}

bool
DumperVisitor::visit(IIR_BlockStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CaseStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CaseStatementAlternativeByChoices *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CaseStatementAlternativeByExpression *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CaseStatementAlternativeByOthers *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CaseStatementAlternativeList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CharacterLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Choice *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ChoiceList *e, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Comment *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_CommentList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ComponentConfiguration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ComponentDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ComponentInstantiationStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcatenationOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentAssertionStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentConditionalSignalAssignment *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentGenerateForStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentGenerateIfStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentProcedureCallStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConcurrentSelectedSignalAssignment *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConditionalWaveform * item, visitor_argument_type * ) {
  os << *item->get_waveform();
  if( item->get_condition() != NULL ){
    os << "when ";
    os << *item->get_condition();
  }

  return true;
}

bool
DumperVisitor::visit(IIR_ConditionalWaveformList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConfigurationDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConfigurationItem *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConfigurationItemList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConfigurationSpecification *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConstantDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ConstantInterfaceDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DeclarationList<> *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DelayedAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignFile *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignFileList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignUnitList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignatorByAll *, visitor_argument_type * ) {
  os << "all";
  return true;
}

bool
DumperVisitor::visit(IIR_DesignatorByOthers *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignatorExplicit *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DesignatorList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DisconnectSpecification *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DivisionOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DrivingAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_DrivingValueAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ElementDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ElementDeclarationList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Elsif *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EntityClassEntry *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EntityClassEntryList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EntityDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EntityNameList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EnumerationLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EnumerationLiteralList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EnumerationSubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EnumerationTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EqualityOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_EventAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ExitStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ExponentiationOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FileDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FileInterfaceDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FileTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FloatingPointLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FloatingPointLiteral32 *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FloatingPointLiteral64 *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FloatingSubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FloatingTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ForLoopStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FunctionCall *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_FunctionDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GenericList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GreaterThanOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GreaterThanOrEqualOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GroupConstituent *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GroupDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_GroupTemplateDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_HighAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Identifier *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IdentifierList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IdentityOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IfStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ImageAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IndexedName *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_InequalityOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_InstanceNameAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IntegerLiteral32 * item, visitor_argument_type * ) {
   os << item->value();
   return true;
}

bool
DumperVisitor::visit(IIR_IntegerLiteral64 *, visitor_argument_type * ) {
   os << item->value();
   return true;
}

bool
DumperVisitor::visit(IIR_IntegerSubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_IntegerTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_InterfaceList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Label *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LastActiveAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LastEventAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LastValueAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LeftAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LeftOfAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LengthAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LessThanOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LessThanOrEqualOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LibraryClause *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LibraryDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LibraryUnitList*, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Literal *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_LowAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ModulusOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_MultiplicationOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Name *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NameList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NandOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NegationOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NextStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NorOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NotOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_NullStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_OrOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_OthersInitialization *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PackageBodyDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PackageDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PathNameAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PhysicalLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PhysicalSubtypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PhysicalTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PhysicalUnit *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PortList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PosAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_PredAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ProcedureCallStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ProcedureDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ProcessStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_QualifiedExpression *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_QuietAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ROLOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ROROperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RangeAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RangeTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RecordTypeDefinition *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RemainderOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ReportStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ReturnStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ReverseRangeAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RightAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_RightOfAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SLAOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SLLOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SRAOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SRLOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SelectedName *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SelectedNameByAll *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SelectedWaveform *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SelectedWaveformList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SensitizedProcessStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SequentialStatementList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SharedVariableDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SignalAssignmentStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SignalDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SignalInterfaceDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Signature *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SimpleName *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SimpleNameAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SliceName *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_StableAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_StringLiteral *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SubprogramDeclaration * item, visitor_argument_type * ) {
  os << *item->get_declarator();
  os << "(";

  IIR_InterfaceDeclaration *current_param = 
    dynamic_cast<IIR_InterfaceDeclaration *>(item->get_interface_declarations()->first());
  while( current_param != NULL ){
    os << *current_param;
    current_param = 
      dynamic_cast<IIR_InterfaceDeclaration *>(item->get_interface_declarations()->successor( current_param ));
    if( current_param != NULL ){
      os << ", ";
    }
  }
  
  os << ")";

  return true;
}

bool
DumperVisitor::visit(IIR_SubtractionOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SubtypeDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_SuccAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_TransactionAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_Tuple *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_TypeConversion * item, visitor_argument_type * ) {
  os << *item->get_type_mark();
  os << " ( ";
  os << *item->get_expression();
  os << " ) ";
  
  return true;
}

bool
DumperVisitor::visit(IIR_TypeDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_UnitList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_UseClause *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_UserAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ValAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_ValueAttribute *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_VariableAssignmentStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_VariableDeclaration *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_VariableInterfaceDeclaration * item, visitor_argument_type * ) {
  os << *item->get_declarator();
  return true;
}

bool
DumperVisitor::visit(IIR_WaitStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_WaveformElement * item, visitor_argument_type * ) {
  os << *item->get_value();

  if (item->get_time()) {
    os << " after ";
    os << *item->get_time();
    os << " ";
  }
  
  return true;
}

bool
DumperVisitor::visit(IIR_WaveformList *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_WhileLoopStatement *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_XnorOperator *, visitor_argument_type * ) {
}

bool
DumperVisitor::visit(IIR_XorOperator *, visitor_argument_type * ) {
}
