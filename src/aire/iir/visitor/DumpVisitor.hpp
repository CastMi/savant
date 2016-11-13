#ifndef DUMP_VISITOR_HH
#define DUMP_VISITOR_HH

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

#include "generic_visitor.hh"
#include "IIR_DeclarationList.hh"
#include <iostream>

class IIR;
class IIR_Statement;
class IIR_AbsoluteOperator;
class IIR_AccessSubtypeDefinition;
class IIR_AccessTypeDefinition;
class IIR_ActiveAttribute;
class IIR_AdditionOperator;
class IIR_Aggregate;
class IIR_AliasDeclaration;
class IIR_Allocator;
class IIR_AndOperator;
class IIR_ArchitectureDeclaration;
class IIR_ArchitectureStatementList;
class IIR_ArraySubtypeDefinition;
class IIR_ArrayTypeDefinition;
class IIR_AscendingAttribute;
class IIR_AssertionStatement;
class IIR_AssociationElementByExpression;
class IIR_AssociationElementOpen;
class IIR_AssociationList;
class IIR_AttributeDeclaration;
class IIR_AttributeSpecification;
class IIR_AttributeSpecificationList;
class IIR_BaseAttribute;
class IIR_BitStringLiteral;
class IIR_BlockConfiguration;
class IIR_BlockStatement;
class IIR_CaseStatement;
class IIR_CaseStatementAlternativeByChoices;
class IIR_CaseStatementAlternativeByExpression;
class IIR_CaseStatementAlternativeByOthers;
class IIR_CaseStatementAlternativeList;
class IIR_CharacterLiteral;
class IIR_Choice;
class IIR_ChoiceList;
class IIR_Comment;
class IIR_CommentList;
class IIR_ComponentConfiguration;
class IIR_ComponentDeclaration;
class IIR_ComponentInstantiationStatement;
class IIR_ConcatenationOperator;
class IIR_ConcurrentAssertionStatement;
class IIR_ConcurrentConditionalSignalAssignment;
class IIR_ConcurrentGenerateForStatement;
class IIR_ConcurrentGenerateIfStatement;
class IIR_ConcurrentProcedureCallStatement;
class IIR_ConcurrentSelectedSignalAssignment;
class IIR_ConditionalWaveform;
class IIR_ConditionalWaveformList;
class IIR_ConfigurationDeclaration;
class IIR_ConfigurationItem;
class IIR_ConfigurationItemList;
class IIR_ConfigurationSpecification;
class IIR_ConstantDeclaration;
class IIR_ConstantInterfaceDeclaration;
class IIR_DelayedAttribute;
class IIR_DesignFile;
class IIR_DesignFileList;
class IIR_DesignUnitList;
class IIR_DesignatorByAll;
class IIR_DesignatorByOthers;
class IIR_DesignatorExplicit;
class IIR_DesignatorList;
class IIR_DisconnectSpecification;
class IIR_DivisionOperator;
class IIR_DrivingAttribute;
class IIR_DrivingValueAttribute;
class IIR_ElementDeclaration;
class IIR_ElementDeclarationList;
class IIR_Elsif;
class IIR_EntityClassEntry;
class IIR_EntityClassEntryList;
class IIR_EntityDeclaration;
class IIR_EntityNameList;
class IIR_EnumerationLiteral;
class IIR_EnumerationLiteralList;
class IIR_EnumerationSubtypeDefinition;
class IIR_EnumerationTypeDefinition;
class IIR_EqualityOperator;
class IIR_EventAttribute;
class IIR_ExitStatement;
class IIR_ExponentiationOperator;
class IIR_FileDeclaration;
class IIR_FileInterfaceDeclaration;
class IIR_FileTypeDefinition;
class IIR_FloatingPointLiteral;
class IIR_FloatingPointLiteral32;
class IIR_FloatingPointLiteral64;
class IIR_FloatingSubtypeDefinition;
class IIR_FloatingTypeDefinition;
class IIR_ForLoopStatement;
class IIR_FunctionCall;
class IIR_FunctionDeclaration;
class IIR_GenericList;
class IIR_GreaterThanOperator;
class IIR_GreaterThanOrEqualOperator;
class IIR_GroupConstituent;
class IIR_GroupDeclaration;
class IIR_GroupTemplateDeclaration;
class IIR_HighAttribute;
class IIR_Identifier;
class IIR_IdentifierList;
class IIR_IdentityOperator;
class IIR_IfStatement;
class IIR_ImageAttribute;
class IIR_IndexedName;
class IIR_InequalityOperator;
class IIR_InstanceNameAttribute;
class IIR_IntegerLiteral;
class IIR_IntegerLiteral32;
class IIR_IntegerLiteral64;
class IIR_InterfaceList;
class IIR_Label;
class IIR_LastActiveAttribute;
class IIR_LastEventAttribute;
class IIR_LastValueAttribute;
class IIR_LeftAttribute;
class IIR_LeftOfAttribute;
class IIR_LengthAttribute;
class IIR_LessThanOperator;
class IIR_LessThanOrEqualOperator;
class IIR_LibraryClause;
class IIR_LibraryDeclaration;
class IIR_LibraryUnitList;
class IIR_Literal;
class IIR_LowAttribute;
class IIR_ModulusOperator;
class IIR_MultiplicationOperator;
class IIR_Name;
class IIR_NameList;
class IIR_NandOperator;
class IIR_NegationOperator;
class IIR_NextStatement;
class IIR_NorOperator;
class IIR_NotOperator;
class IIR_NullStatement;
class IIR_OrOperator;
class IIR_OthersInitialization;
class IIR_PackageBodyDeclaration;
class IIR_PackageDeclaration;
class IIR_PathNameAttribute;
class IIR_PhysicalLiteral;
class IIR_PhysicalSubtypeDefinition;
class IIR_PhysicalTypeDefinition;
class IIR_PhysicalUnit;
class IIR_PortList;
class IIR_PosAttribute;
class IIR_PredAttribute;
class IIR_ProcedureCallStatement;
class IIR_ProcedureDeclaration;
class IIR_ProcessStatement;
class IIR_QualifiedExpression;
class IIR_QuietAttribute;
class IIR_ROLOperator;
class IIR_ROROperator;
class IIR_RangeAttribute;
class IIR_RangeTypeDefinition;
class IIR_RecordTypeDefinition;
class IIR_RemainderOperator;
class IIR_ReportStatement;
class IIR_ReturnStatement;
class IIR_ReverseRangeAttribute;
class IIR_RightAttribute;
class IIR_RightOfAttribute;
class IIR_SLAOperator;
class IIR_SLLOperator;
class IIR_SRAOperator;
class IIR_SRLOperator;
class IIR_SelectedName;
class IIR_SelectedNameByAll;
class IIR_SelectedWaveform;
class IIR_SelectedWaveformList;
class IIR_SensitizedProcessStatement;
class IIR_SequentialStatementList;
class IIR_SharedVariableDeclaration;
class IIR_SignalAssignmentStatement;
class IIR_SignalDeclaration;
class IIR_SignalInterfaceDeclaration;
class IIR_Signature;
class IIR_SimpleName;
class IIR_SimpleNameAttribute;
class IIR_SliceName;
class IIR_StableAttribute;
class IIR_StringLiteral;
class IIR_SubprogramDeclaration;
class IIR_SubtractionOperator;
class IIR_SubtypeDeclaration;
class IIR_SuccAttribute;
class IIR_TransactionAttribute;
class IIR_Tuple;
class IIR_TypeConversion;
class IIR_TypeDeclaration;
class IIR_UnitList;
class IIR_UseClause;
class IIR_UserAttribute;
class IIR_ValAttribute;
class IIR_ValueAttribute;
class IIR_VariableAssignmentStatement;
class IIR_VariableDeclaration;
class IIR_VariableInterfaceDeclaration;
class IIR_WaitStatement;
class IIR_WaveformElement;
class IIR_WaveformList;
class IIR_WhileLoopStatement;
class IIR_XnorOperator;
class IIR_XorOperator;
class IIR_IntegerSubtypeDefinition;
class IIR_IntegerTypeDefinition;

/** 
*/
class DumpVisitor : public generic_visitor {

public: 
  /// Constructor.
  DumpVisitor( std::ostream& output = std::cout ) : out(output) {};
  virtual ~DumpVisitor() {};
  
  /** Visitor method for objects of type IIR_AbsoluteOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AbsoluteOperator * );


  /** Visitor method for objects of type IIR_AccessSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AccessSubtypeDefinition * );


  /** Visitor method for objects of type IIR_AccessTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AccessTypeDefinition * );


  /** Visitor method for objects of type IIR_ActiveAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ActiveAttribute * );


  /** Visitor method for objects of type IIR_AdditionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AdditionOperator * );


  /** Visitor method for objects of type IIR_Aggregate.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Aggregate * );


  /** Visitor method for objects of type IIR_AliasDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AliasDeclaration * );


  /** Visitor method for objects of type IIR_Allocator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Allocator * );


  /** Visitor method for objects of type IIR_AndOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AndOperator * );


  /** Visitor method for objects of type IIR_ArchitectureDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ArchitectureDeclaration * );


  /** Visitor method for objects of type IIR_ArchitectureStatementList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ArchitectureStatementList * );


  /** Visitor method for objects of type IIR_ArraySubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ArraySubtypeDefinition * );


  /** Visitor method for objects of type IIR_ArrayTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ArrayTypeDefinition * );


  /** Visitor method for objects of type IIR_AscendingAttribute.
      @return container for any return value wanted by  the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AscendingAttribute * );


  /** Visitor method for objects of type IIR_AssertionStatement.
      @return container for any return value wanted by t he visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AssertionStatement * );


  /** Visitor method for objects of type IIR_AssociationElementByExpression.
      @return container for any return value want ed by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AssociationElementByExpression * );


  /** Visitor method for objects of type IIR_AssociationElementOpen.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AssociationElementOpen * );


  /** Visitor method for objects of type IIR_AssociationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AssociationList * );


  /** Visitor method for objects of type IIR_AttributeDeclaration.
      @return container for any return value wanted b y the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AttributeDeclaration * );


  /** Visitor method for objects of type IIR_AttributeSpecification.
      @return container for any return value wanted by the visitor. 
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AttributeSpecification * );


  /** Visitor method for objects of type IIR_AttributeSpecificationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_AttributeSpecificationList * );


  /** Visitor method for objects of type IIR_BaseAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_BaseAttribute * );


  /** Visitor method for objects of type IIR_BitStringLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_BitStringLiteral * );


  /** Visitor method for objects of type IIR_BlockConfiguration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_BlockConfiguration * );


  /** Visitor method for objects of type IIR_BlockStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_BlockStatement * );


  /** Visitor method for objects of type IIR_CaseStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CaseStatement * );


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByChoices.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CaseStatementAlternativeByChoices * );


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByExpression.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CaseStatementAlternativeByExpression * );


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByOthers.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CaseStatementAlternativeByOthers * );


  /** Visitor method for objects of type IIR_CaseStatementAlternativeList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CaseStatementAlternativeList * );


  /** Visitor method for objects of type IIR_CharacterLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CharacterLiteral * );


  /** Visitor method for objects of type IIR_Choice.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Choice * );


  /** Visitor method for objects of type IIR_ChoiceList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ChoiceList *e );


  /** Visitor method for objects of type IIR_Comment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Comment * );


  /** Visitor method for objects of type IIR_CommentList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_CommentList * );


  /** Visitor method for objects of type IIR_ComponentConfiguration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ComponentConfiguration * );


  /** Visitor method for objects of type IIR_ComponentDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ComponentDeclaration * );


  /** Visitor method for objects of type IIR_ComponentInstantiationStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ComponentInstantiationStatement * );


  /** Visitor method for objects of type IIR_ConcatenationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcatenationOperator * );


  /** Visitor method for objects of type IIR_ConcurrentAssertionStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentAssertionStatement * );


  /** Visitor method for objects of type IIR_ConcurrentConditionalSignalAssignment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentConditionalSignalAssignment * );


  /** Visitor method for objects of type IIR_ConcurrentGenerateForStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentGenerateForStatement * );


  /** Visitor method for objects of type IIR_ConcurrentGenerateIfStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentGenerateIfStatement * );


  /** Visitor method for objects of type IIR_ConcurrentProcedureCallStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentProcedureCallStatement * );


  /** Visitor method for objects of type IIR_ConcurrentSelectedSignalAssignment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConcurrentSelectedSignalAssignment * );


  /** Visitor method for objects of type IIR_ConditionalWaveform.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConditionalWaveform * );


  /** Visitor method for objects of type IIR_ConditionalWaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConditionalWaveformList * );


  /** Visitor method for objects of type IIR_ConfigurationDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConfigurationDeclaration * );


  /** Visitor method for objects of type IIR_ConfigurationItem.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConfigurationItem * );


  /** Visitor method for objects of type IIR_ConfigurationItemList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConfigurationItemList * );


  /** Visitor method for objects of type IIR_ConfigurationSpecification.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConfigurationSpecification * );


  /** Visitor method for objects of type IIR_ConstantDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConstantDeclaration * );


  /** Visitor method for objects of type IIR_ConstantInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ConstantInterfaceDeclaration * );


  /** Visitor method for objects of type IIR_DeclarationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DeclarationList<> * );


  /** Visitor method for objects of type IIR_DelayedAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DelayedAttribute * );


  /** Visitor method for objects of type IIR_DesignFile.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignFile * );


  /** Visitor method for objects of type IIR_DesignFileList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignFileList * );


  /** Visitor method for objects of type IIR_DesignUnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignUnitList * );


  /** Visitor method for objects of type IIR_DesignatorByAll.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignatorByAll * );


  /** Visitor method for objects of type IIR_DesignatorByOthers.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignatorByOthers * );


  /** Visitor method for objects of type IIR_DesignatorExplicit.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignatorExplicit * );


  /** Visitor method for objects of type IIR_DesignatorList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DesignatorList * );


  /** Visitor method for objects of type IIR_DisconnectSpecification.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DisconnectSpecification * );


  /** Visitor method for objects of type IIR_DivisionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DivisionOperator * );


  /** Visitor method for objects of type IIR_DrivingAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DrivingAttribute * );


  /** Visitor method for objects of type IIR_DrivingValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_DrivingValueAttribute * );


  /** Visitor method for objects of type IIR_ElementDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ElementDeclaration * );


  /** Visitor method for objects of type IIR_ElementDeclarationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ElementDeclarationList * );


  /** Visitor method for objects of type IIR_Elsif.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Elsif * );


  /** Visitor method for objects of type IIR_EntityClassEntry.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EntityClassEntry * );


  /** Visitor method for objects of type IIR_EntityClassEntryList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EntityClassEntryList * );


  /** Visitor method for objects of type IIR_EntityDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EntityDeclaration * );


  /** Visitor method for objects of type IIR_EntityNameList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EntityNameList * );


  /** Visitor method for objects of type IIR_EnumerationLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EnumerationLiteral * );


  /** Visitor method for objects of type IIR_EnumerationLiteralList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EnumerationLiteralList * );


  /** Visitor method for objects of type IIR_EnumerationSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EnumerationSubtypeDefinition * );


  /** Visitor method for objects of type IIR_EnumerationTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EnumerationTypeDefinition * );


  /** Visitor method for objects of type IIR_EqualityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EqualityOperator * );


  /** Visitor method for objects of type IIR_EventAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_EventAttribute * );


  /** Visitor method for objects of type IIR_ExitStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ExitStatement * );


  /** Visitor method for objects of type IIR_ExponentiationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ExponentiationOperator * );


  /** Visitor method for objects of type IIR_FileDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FileDeclaration * );


  /** Visitor method for objects of type IIR_FileInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FileInterfaceDeclaration * );


  /** Visitor method for objects of type IIR_FileTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FileTypeDefinition * );


  /** Visitor method for objects of type IIR_FloatingPointLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FloatingPointLiteral * );


  /** Visitor method for objects of type IIR_FloatingPointLiteral32.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FloatingPointLiteral32 * );


  /** Visitor method for objects of type IIR_FloatingPointLiteral64.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FloatingPointLiteral64 * );


  /** Visitor method for objects of type IIR_FloatingSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FloatingSubtypeDefinition * );


  /** Visitor method for objects of type IIR_FloatingTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FloatingTypeDefinition * );


  /** Visitor method for objects of type IIR_ForLoopStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ForLoopStatement * );


  /** Visitor method for objects of type IIR_FunctionCall.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FunctionCall * );


  /** Visitor method for objects of type IIR_FunctionDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_FunctionDeclaration * );


  /** Visitor method for objects of type IIR_GenericList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GenericList * );


  /** Visitor method for objects of type IIR_GreaterThanOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GreaterThanOperator * );


  /** Visitor method for objects of type IIR_GreaterThanOrEqualOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GreaterThanOrEqualOperator * );


  /** Visitor method for objects of type IIR_GroupConstituent.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GroupConstituent * );


  /** Visitor method for objects of type IIR_GroupDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GroupDeclaration * );


  /** Visitor method for objects of type IIR_GroupTemplateDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_GroupTemplateDeclaration * );


  /** Visitor method for objects of type IIR_HighAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_HighAttribute * );


  /** Visitor method for objects of type IIR_Identifier.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Identifier * );


  /** Visitor method for objects of type IIR_IdentifierList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IdentifierList * );


  /** Visitor method for objects of type IIR_IdentityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IdentityOperator * );


  /** Visitor method for objects of type IIR_IfStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IfStatement * );


  /** Visitor method for objects of type IIR_ImageAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ImageAttribute * );


  /** Visitor method for objects of type IIR_IndexedName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IndexedName * );


  /** Visitor method for objects of type IIR_InequalityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_InequalityOperator * );


  /** Visitor method for objects of type IIR_InstanceNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_InstanceNameAttribute * );


  /** Visitor method for objects of type IIR_IntegerLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IntegerLiteral * );


  /** Visitor method for objects of type IIR_IntegerLiteral32.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IntegerLiteral32 * );


  /** Visitor method for objects of type IIR_IntegerLiteral64.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IntegerLiteral64 * );


  /** Visitor method for objects of type IIR_IntegerSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IntegerSubtypeDefinition * );


  /** Visitor method for objects of type IIR_IntegerTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_IntegerTypeDefinition * );


  /** Visitor method for objects of type IIR_InterfaceList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_InterfaceList * );


  /** Visitor method for objects of type IIR_Label.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Label * );


  /** Visitor method for objects of type IIR_LastActiveAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LastActiveAttribute * );


  /** Visitor method for objects of type IIR_LastEventAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LastEventAttribute * );


  /** Visitor method for objects of type IIR_LastValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LastValueAttribute * );


  /** Visitor method for objects of type IIR_LeftAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LeftAttribute * );


  /** Visitor method for objects of type IIR_LeftOfAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LeftOfAttribute * );


  /** Visitor method for objects of type IIR_LengthAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LengthAttribute * );


  /** Visitor method for objects of type IIR_LessThanOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LessThanOperator * );


  /** Visitor method for objects of type IIR_LessThanOrEqualOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LessThanOrEqualOperator * );


  /** Visitor method for objects of type IIR_LibraryClause.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LibraryClause * );


  /** Visitor method for objects of type IIR_LibraryDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LibraryDeclaration * );


  /** Visitor method for objects of type IIR_LibraryUnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LibraryUnitList* );


  /** Visitor method for objects of type IIR_Literal.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Literal * );


  /** Visitor method for objects of type IIR_LowAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_LowAttribute * );


  /** Visitor method for objects of type IIR_ModulusOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ModulusOperator * );


  /** Visitor method for objects of type IIR_MultiplicationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_MultiplicationOperator * );


  /** Visitor method for objects of type IIR_Name.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Name * );


  /** Visitor method for objects of type IIR_NameList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NameList * );


  /** Visitor method for objects of type IIR_NandOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NandOperator * );


  /** Visitor method for objects of type IIR_NegationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NegationOperator * );


  /** Visitor method for objects of type IIR_NextStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NextStatement * );


  /** Visitor method for objects of type IIR_NorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NorOperator * );


  /** Visitor method for objects of type IIR_NotOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NotOperator * );


  /** Visitor method for objects of type IIR_NullStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_NullStatement * );


  /** Visitor method for objects of type IIR_OrOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_OrOperator * );


  /** Visitor method for objects of type IIR_OthersInitialization.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_OthersInitialization * );


  /** Visitor method for objects of type IIR_PackageBodyDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PackageBodyDeclaration * );


  /** Visitor method for objects of type IIR_PackageDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PackageDeclaration * );


  /** Visitor method for objects of type IIR_PathNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PathNameAttribute * );


  /** Visitor method for objects of type IIR_PhysicalLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PhysicalLiteral * );


  /** Visitor method for objects of type IIR_PhysicalSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PhysicalSubtypeDefinition * );


  /** Visitor method for objects of type IIR_PhysicalTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PhysicalTypeDefinition * );


  /** Visitor method for objects of type IIR_PhysicalUnit.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PhysicalUnit * );


  /** Visitor method for objects of type IIR_PortList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PortList * );


  /** Visitor method for objects of type IIR_PosAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PosAttribute * );


  /** Visitor method for objects of type IIR_PredAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_PredAttribute * );


  /** Visitor method for objects of type IIR_ProcedureCallStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ProcedureCallStatement * );


  /** Visitor method for objects of type IIR_ProcedureDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ProcedureDeclaration * );


  /** Visitor method for objects of type IIR_ProcessStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ProcessStatement * );


  /** Visitor method for objects of type IIR_QualifiedExpression.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_QualifiedExpression * );


  /** Visitor method for objects of type IIR_QuietAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_QuietAttribute * );


  /** Visitor method for objects of type IIR_ROLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ROLOperator * );


  /** Visitor method for objects of type IIR_ROROperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ROROperator * );


  /** Visitor method for objects of type IIR_RangeAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RangeAttribute * );


  /** Visitor method for objects of type IIR_RangeTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RangeTypeDefinition * );


  /** Visitor method for objects of type IIR_RecordTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RecordTypeDefinition * );


  /** Visitor method for objects of type IIR_RemainderOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RemainderOperator * );


  /** Visitor method for objects of type IIR_ReportStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ReportStatement * );


  /** Visitor method for objects of type IIR_ReturnStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ReturnStatement * );


  /** Visitor method for objects of type IIR_ReverseRangeAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ReverseRangeAttribute * );


  /** Visitor method for objects of type IIR_RightAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RightAttribute * );


  /** Visitor method for objects of type IIR_RightOfAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_RightOfAttribute * );


  /** Visitor method for objects of type IIR_SLAOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SLAOperator * );


  /** Visitor method for objects of type IIR_SLLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SLLOperator * );


  /** Visitor method for objects of type IIR_SRAOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SRAOperator * );


  /** Visitor method for objects of type IIR_SRLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SRLOperator * );


  /** Visitor method for objects of type IIR_SelectedName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SelectedName * );


  /** Visitor method for objects of type IIR_SelectedNameByAll.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SelectedNameByAll * );


  /** Visitor method for objects of type IIR_SelectedWaveform.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SelectedWaveform * );


  /** Visitor method for objects of type IIR_SelectedWaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SelectedWaveformList * );


  /** Visitor method for objects of type IIR_SensitizedProcessStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SensitizedProcessStatement * );


  /** Visitor method for objects of type IIR_SequentialStatementList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SequentialStatementList * );


  /** Visitor method for objects of type IIR_SharedVariableDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SharedVariableDeclaration * );


  /** Visitor method for objects of type IIR_SignalAssignmentStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SignalAssignmentStatement * );


  /** Visitor method for objects of type IIR_SignalDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SignalDeclaration * );


  /** Visitor method for objects of type IIR_SignalInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SignalInterfaceDeclaration * );


  /** Visitor method for objects of type IIR_Signature.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Signature * );


  /** Visitor method for objects of type IIR_SimpleName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SimpleName * );


  /** Visitor method for objects of type IIR_SimpleNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SimpleNameAttribute * );


  /** Visitor method for objects of type IIR_SliceName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SliceName * );


  /** Visitor method for objects of type IIR_StableAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_StableAttribute * );


  /** Visitor method for objects of type IIR_StringLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_StringLiteral * );


  /** Visitor method for objects of type IIR_SubprogramDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SubprogramDeclaration * );


  /** Visitor method for objects of type IIR_SubtractionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SubtractionOperator * );


  /** Visitor method for objects of type IIR_SubtypeDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SubtypeDeclaration * );


  /** Visitor method for objects of type IIR_SuccAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_SuccAttribute * );


  /** Visitor method for objects of type IIR_TransactionAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_TransactionAttribute * );


  /** Visitor method for objects of type IIR_Tuple.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_Tuple * );


  /** Visitor method for objects of type IIR_TypeConversion.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_TypeConversion * );


  /** Visitor method for objects of type IIR_TypeDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_TypeDeclaration * );


  /** Visitor method for objects of type IIR_UnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_UnitList * );


  /** Visitor method for objects of type IIR_UseClause.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_UseClause * );


  /** Visitor method for objects of type IIR_UserAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_UserAttribute * );


  /** Visitor method for objects of type IIR_ValAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ValAttribute * );


  /** Visitor method for objects of type IIR_ValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_ValueAttribute * );


  /** Visitor method for objects of type IIR_VariableAssignmentStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_VariableAssignmentStatement * );


  /** Visitor method for objects of type IIR_VariableDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_VariableDeclaration * );


  /** Visitor method for objects of type IIR_VariableInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_VariableInterfaceDeclaration * );


  /** Visitor method for objects of type IIR_WaitStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_WaitStatement * );


  /** Visitor method for objects of type IIR_WaveformElement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_WaveformElement * );


  /** Visitor method for objects of type IIR_WaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_WaveformList * );


  /** Visitor method for objects of type IIR_WhileLoopStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_WhileLoopStatement * );


  /** Visitor method for objects of type IIR_XnorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_XnorOperator * );


  /** Visitor method for objects of type IIR_XorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  bool visit(IIR_XorOperator * );

private:
  std::ostream& out;

};

#endif // DUMP_VISITOR_HH
