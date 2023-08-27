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
    class MutatorReverseIfCond : public TransformerClangTidyCheck {
       public:
        MutatorReverseIfCond(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                      ifStmt(hasCondition(expr().bind("cond"))).bind("if"),
                      changeTo(node("cond"), cat("!(", node("cond"), ")")),
                      cat("if condition mutated")),
                  Name,
                  Context) { }
    };
}  // namespace clang::tidy::mutator