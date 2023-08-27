#pragma once

#include "common.h"
using namespace clang::transformer;
using namespace clang::tidy::utils;
using namespace clang::ast_matchers;

namespace clang::tidy::mutator {
    class MutatorTrueToFalse : public TransformerClangTidyCheck {
       public:
        MutatorTrueToFalse(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(cxxBoolLiteral(equals(true)), changeTo(cat("false")), cat("true mutated to false")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator