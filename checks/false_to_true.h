#pragma once

#include "common.h"

using namespace clang::transformer;
using namespace clang::tidy::utils;
using namespace clang::ast_matchers;

namespace clang::tidy::mutator {
    class MutatorFalseToTrue : public TransformerClangTidyCheck {
       public:
        MutatorFalseToTrue(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(cxxBoolLiteral(equals(false)).bind("bool"), changeTo(cat("true")), cat("false mutated to true")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator