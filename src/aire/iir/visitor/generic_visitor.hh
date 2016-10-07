#ifndef NODE_VISITOR_HH
#define NODE_VISITOR_HH

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

#include "visitor_argument_type.hh"
#include "IIR_DeclarationList.hh"

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

/** This class contains the interface definition for visitors to the IIR
    intermediate form package \Ref{IIR}.  All visitor methods in this
    package are declared pure virtual so any visitor type derived from this
    class must provide an implementation for each.

    An important aspect of this visitor pattern is that it supports
    parameter transmission.  Each method has two arguments, the first is a
    pointer to the IIR object related to this visitation and the second is
    an general {\tt visitor_argument_type*} argument that is provided for
    use by any instantiated visitor object; each method also has a return
    signature bool.

    @see visitor_argument_type
*/
class generic_visitor {

public: 
  /// Constructor.
  generic_visitor() {};
  virtual ~generic_visitor() {};
  
  // Dispatch methods
  bool visit(IIR *, visitor_argument_type * = nullptr );
  bool visit(IIR_Statement *, visitor_argument_type * = nullptr);

  /** Visitor method for objects of type IIR_AbsoluteOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AbsoluteOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AccessSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AccessSubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AccessTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AccessTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ActiveAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ActiveAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AdditionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AdditionOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Aggregate.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Aggregate *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AliasDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AliasDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Allocator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Allocator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AndOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AndOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ArchitectureDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ArchitectureDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ArchitectureStatementList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ArchitectureStatementList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ArraySubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ArraySubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ArrayTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ArrayTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AscendingAttribute.
      @return container for any return value wanted by  the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AscendingAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AssertionStatement.
      @return container for any return value wanted by t he visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AssertionStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AssociationElementByExpression.
      @return container for any return value want ed by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AssociationElementByExpression *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AssociationElementOpen.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AssociationElementOpen *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AssociationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AssociationList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AttributeDeclaration.
      @return container for any return value wanted b y the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AttributeDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AttributeSpecification.
      @return container for any return value wanted by the visitor. 
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AttributeSpecification *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_AttributeSpecificationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_AttributeSpecificationList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_BaseAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_BaseAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_BitStringLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_BitStringLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_BlockConfiguration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_BlockConfiguration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_BlockStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_BlockStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CaseStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CaseStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByChoices.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CaseStatementAlternativeByChoices *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByExpression.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CaseStatementAlternativeByExpression *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CaseStatementAlternativeByOthers.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CaseStatementAlternativeByOthers *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CaseStatementAlternativeList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CaseStatementAlternativeList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CharacterLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CharacterLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Choice.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Choice *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ChoiceList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ChoiceList *e, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Comment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Comment *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_CommentList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_CommentList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ComponentConfiguration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ComponentConfiguration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ComponentDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ComponentDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ComponentInstantiationStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ComponentInstantiationStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcatenationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcatenationOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentAssertionStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentAssertionStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentConditionalSignalAssignment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentConditionalSignalAssignment *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentGenerateForStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentGenerateForStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentGenerateIfStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentGenerateIfStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentProcedureCallStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentProcedureCallStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConcurrentSelectedSignalAssignment.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConcurrentSelectedSignalAssignment *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConditionalWaveform.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConditionalWaveform *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConditionalWaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConditionalWaveformList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConfigurationDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConfigurationDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConfigurationItem.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConfigurationItem *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConfigurationItemList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConfigurationItemList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConfigurationSpecification.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConfigurationSpecification *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConstantDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConstantDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ConstantInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ConstantInterfaceDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DeclarationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DeclarationList<> *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DelayedAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DelayedAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignFile.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignFile *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignFileList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignFileList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignUnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignUnitList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignatorByAll.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignatorByAll *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignatorByOthers.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignatorByOthers *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignatorExplicit.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignatorExplicit *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DesignatorList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DesignatorList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DisconnectSpecification.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DisconnectSpecification *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DivisionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DivisionOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DrivingAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DrivingAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_DrivingValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_DrivingValueAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ElementDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ElementDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ElementDeclarationList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ElementDeclarationList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Elsif.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Elsif *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EntityClassEntry.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EntityClassEntry *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EntityClassEntryList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EntityClassEntryList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EntityDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EntityDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EntityNameList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EntityNameList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EnumerationLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EnumerationLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EnumerationLiteralList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EnumerationLiteralList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EnumerationSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EnumerationSubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EnumerationTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EnumerationTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EqualityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EqualityOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_EventAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_EventAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ExitStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ExitStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ExponentiationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ExponentiationOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FileDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FileDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FileInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FileInterfaceDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FileTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FileTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FloatingPointLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FloatingPointLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FloatingPointLiteral32.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FloatingPointLiteral32 *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FloatingPointLiteral64.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FloatingPointLiteral64 *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FloatingSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FloatingSubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FloatingTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FloatingTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ForLoopStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ForLoopStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FunctionCall.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FunctionCall *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_FunctionDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_FunctionDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GenericList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GenericList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GreaterThanOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GreaterThanOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GreaterThanOrEqualOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GreaterThanOrEqualOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GroupConstituent.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GroupConstituent *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GroupDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GroupDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_GroupTemplateDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_GroupTemplateDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_HighAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_HighAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Identifier.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Identifier *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IdentifierList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IdentifierList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IdentityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IdentityOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IfStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IfStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ImageAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ImageAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IndexedName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IndexedName *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_InequalityOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_InequalityOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_InstanceNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_InstanceNameAttribute *, visitor_argument_type * = nullptr ) = 0;

  /** Visitor method for objects of type IIR_IntegerLiteral32.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IntegerLiteral32 *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IntegerLiteral64.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IntegerLiteral64 *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IntegerSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IntegerSubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_IntegerTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_IntegerTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_InterfaceList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_InterfaceList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Label.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Label *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LastActiveAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LastActiveAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LastEventAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LastEventAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LastValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LastValueAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LeftAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LeftAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LeftOfAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LeftOfAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LengthAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LengthAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LessThanOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LessThanOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LessThanOrEqualOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LessThanOrEqualOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LibraryClause.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LibraryClause *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LibraryDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LibraryDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LibraryUnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LibraryUnitList*, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Literal.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Literal *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_LowAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_LowAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ModulusOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ModulusOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_MultiplicationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_MultiplicationOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Name.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Name *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NameList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NameList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NandOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NandOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NegationOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NegationOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NextStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NextStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NorOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NotOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NotOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_NullStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_NullStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_OrOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_OrOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_OthersInitialization.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_OthersInitialization *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PackageBodyDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PackageBodyDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PackageDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PackageDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PathNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PathNameAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PhysicalLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PhysicalLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PhysicalSubtypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PhysicalSubtypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PhysicalTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PhysicalTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PhysicalUnit.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PhysicalUnit *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PortList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PortList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PosAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PosAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_PredAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_PredAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ProcedureCallStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ProcedureCallStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ProcedureDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ProcedureDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ProcessStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ProcessStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_QualifiedExpression.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_QualifiedExpression *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_QuietAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_QuietAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ROLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ROLOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ROROperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ROROperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RangeAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RangeAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RangeTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RangeTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RecordTypeDefinition.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RecordTypeDefinition *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RemainderOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RemainderOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ReportStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ReportStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ReturnStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ReturnStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ReverseRangeAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ReverseRangeAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RightAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RightAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_RightOfAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_RightOfAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SLAOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SLAOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SLLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SLLOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SRAOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SRAOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SRLOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SRLOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SelectedName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SelectedName *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SelectedNameByAll.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SelectedNameByAll *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SelectedWaveform.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SelectedWaveform *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SelectedWaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SelectedWaveformList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SensitizedProcessStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SensitizedProcessStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SequentialStatementList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SequentialStatementList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SharedVariableDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SharedVariableDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SignalAssignmentStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SignalAssignmentStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SignalDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SignalDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SignalInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SignalInterfaceDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Signature.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Signature *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SimpleName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SimpleName *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SimpleNameAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SimpleNameAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SliceName.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SliceName *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_StableAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_StableAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_StringLiteral.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_StringLiteral *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SubprogramDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SubprogramDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SubtractionOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SubtractionOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SubtypeDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SubtypeDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_SuccAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_SuccAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_TransactionAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_TransactionAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_Tuple.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_Tuple *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_TypeConversion.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_TypeConversion *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_TypeDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_TypeDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_UnitList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_UnitList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_UseClause.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_UseClause *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_UserAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_UserAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ValAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ValAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_ValueAttribute.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_ValueAttribute *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_VariableAssignmentStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_VariableAssignmentStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_VariableDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_VariableDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_VariableInterfaceDeclaration.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_VariableInterfaceDeclaration *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_WaitStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_WaitStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_WaveformElement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_WaveformElement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_WaveformList.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_WaveformList *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_WhileLoopStatement.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_WhileLoopStatement *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_XnorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_XnorOperator *, visitor_argument_type * = nullptr ) = 0;


  /** Visitor method for objects of type IIR_XorOperator.
      @return container for any return value wanted by the visitor.
      @param node a pointer to the \Ref{AIRE-IIR} object related to this
      visitation 
      @param arg container for any argument wanted by the visitor.
  */
  virtual bool visit(IIR_XorOperator *, visitor_argument_type * = nullptr ) = 0;

};

#endif
