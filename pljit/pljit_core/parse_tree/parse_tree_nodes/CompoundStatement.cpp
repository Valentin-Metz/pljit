#include "CompoundStatement.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {

CompoundStatement::CompoundStatement(TerminalSymbol begin, lexer::Lexer& l) : begin(begin), statementList(l) {}

} // namespace parse_tree
