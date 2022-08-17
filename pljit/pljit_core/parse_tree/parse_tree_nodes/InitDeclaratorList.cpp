#include "InitDeclaratorList.hpp"
#include "Factory.hpp"

namespace parse_tree {

static const std::vector<std::pair<const InitDeclarator, const TerminalSymbol>> generateInitDeclaratorList(lexer::Lexer& l) {
    std::vector<std::pair<const InitDeclarator, const TerminalSymbol>> init_declarator_list;
    while (true) {
        InitDeclarator init_declarator{l};
        const std::pair<const Factory::SeparatorType, const TerminalSymbol> separator = Factory::produceSeparator(l);
        init_declarator_list.push_back(std::make_pair(init_declarator, separator.second));
        if (separator.first == Factory::SEMICOLON) return init_declarator_list;
    }
}

InitDeclaratorList::InitDeclaratorList(lexer::Lexer& l) : initDeclaratorList(generateInitDeclaratorList(l)) {}

} // namespace parse_tree