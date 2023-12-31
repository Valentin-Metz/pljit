set(AST_SOURCES
        Ast.cpp
        Ast.hpp
        ast_core/SymbolTable.cpp
        ast_core/SymbolTable.hpp
        ast_nodes/Statement.cpp
        ast_nodes/Statement.hpp
        ast_nodes/Expression.cpp
        ast_nodes/Expression.hpp
        ast_nodes/ReturnStatement.cpp
        ast_nodes/ReturnStatement.hpp
        ast_nodes/AssignmentStatement.cpp
        ast_nodes/AssignmentStatement.hpp
        ast_nodes/Function.cpp
        ast_nodes/Function.hpp
        ast_nodes/TerminalExpression.cpp
        ast_nodes/TerminalExpression.hpp
        ast_nodes/MultiplicativeExpression.cpp
        ast_nodes/MultiplicativeExpression.hpp
        ast_core/AstVisitor.hpp
        print/AstPrintVisitor.cpp
        print/AstPrintVisitor.hpp
        ast_core/ExecutionTable.cpp
        ast_core/ExecutionTable.hpp
        optimization/OptimizationPass.hpp
        optimization/ConstantPropagationOptimizationPass.cpp
        optimization/ConstantPropagationOptimizationPass.hpp
        optimization/DeadCodeEliminationOptimizationPass.cpp
        optimization/DeadCodeEliminationOptimizationPass.hpp
        optimization/ConstantPropagationVisitor.cpp
        optimization/ConstantPropagationVisitor.hpp
        optimization/DeadCodeEliminationVisitor.cpp
        optimization/DeadCodeEliminationVisitor.hpp
        )

add_library(ast ${AST_SOURCES})
target_link_libraries(ast parse_tree error_management source_code_management)
