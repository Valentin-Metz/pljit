#include "DeclaratorList.hpp"
#include "Factory.hpp"

namespace parse_tree {

static const std::vector<std::pair<const Identifier, const TerminalSymbol>> generateDeclaratorList(lexer::Lexer& l) {
    std::vector<std::pair<const Identifier, const TerminalSymbol>> declarator_list;
    while (true) {
        const Identifier identifier = Identifier(l);
        const std::pair<const Factory::SeparatorType, const TerminalSymbol> separator = Factory::produceSeparator(l);
        declarator_list.push_back(std::make_pair(identifier, separator.second));
        if (separator.first == Factory::SEMICOLON) return declarator_list;
    }
}

DeclaratorList::DeclaratorList(lexer::Lexer& l) : declaratorList(generateDeclaratorList(l)) {}
void DeclaratorList::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
