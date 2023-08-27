#pragma once

#include "common.h"
namespace clang::tidy::mutator {

    auto binaryOperatorMatcher =
        binaryOperator(hasOperatorName("=="), hasLHS(expr().bind("lhs")), hasRHS(expr().bind("rhs"))).bind("op");

    class MutatorEqToNeq : public TransformerClangTidyCheck {
       public:
        MutatorEqToNeq(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(binaryOperatorMatcher, changeTo(cat(node("lhs"), " != ", node("rhs"))), cat("!= mutated to ==")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator