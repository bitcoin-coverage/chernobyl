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
    class MutatorFalseToTrue : public TransformerClangTidyCheck {
       public:
        MutatorFalseToTrue(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                        cxxBoolLiteral(equals(false)).bind("bool"),
                        changeTo(cat("true")),
                        cat("false mutated to true")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator