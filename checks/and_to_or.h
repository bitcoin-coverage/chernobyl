#pragma once

#include "common.h"

using namespace clang::transformer;
using namespace clang::tidy::utils;
using namespace clang::ast_matchers;

namespace clang::tidy::mutator {
    class MutatorAndToOr : public TransformerClangTidyCheck {
       public:
        MutatorAndToOr(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                      binaryOperation(hasOperatorName("&&"), hasLHS(expr().bind("lhs")), hasRHS(expr().bind("rhs")))
                          .bind("op"),
                      changeTo(cat(node("lhs"), " || ", node("rhs"))),
                      cat("&& mutated to ||")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator