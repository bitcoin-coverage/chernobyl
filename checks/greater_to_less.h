#pragma once

#include "clang-tidy/ClangTidy.h"
#include "clang-tidy/utils/TransformerClangTidyCheck.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Tooling/Transformer/Stencil.h"
#include "clang/Tooling/Transformer/Transformer.h"

using namespace clang::transformer;
using namespace clang::tidy::utils;
using namespace clang::ast_matchers;

namespace clang::tidy::mutator {
    class MutatorGreaterToLess : public TransformerClangTidyCheck {
       public:
        MutatorGreaterToLess(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                    binaryOperator(hasOperatorName(">"), hasLHS(expr().bind("lhs")), hasRHS(expr().bind("rhs"))),
                    changeTo(cat(node("lhs"), " < ", node("rhs"))),
                    cat("> mutated to <")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator