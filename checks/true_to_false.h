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
    class MutatorTrueToFalse : public TransformerClangTidyCheck {
       public:
        MutatorTrueToFalse(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                        cxxBoolLiteral(equals(true)),
                        changeTo(cat("false")),
                        cat("true mutated to false")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator