#include "checks/and_to_or.h"
#include "checks/eq_to_neq.h"
#include "checks/false_to_true.h"
#include "checks/greater_eq_to_less_eq.h"
#include "checks/greater_to_less.h"
#include "checks/less_eq_to_greater_eq.h"
#include "checks/less_to_greater.h"
#include "checks/neq_to_eq.h"
#include "checks/or_to_and.h"
#include "checks/reverse_if_cond.h"
#include "checks/true_to_false.h"
#include "clang-tidy/ClangTidy.h"
#include "clang-tidy/ClangTidyModule.h"
#include "clang-tidy/ClangTidyModuleRegistry.h"

namespace clang::tidy {
    namespace mutator {
        class MutatorModule : public ClangTidyModule {
           public:
            void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
                CheckFactories.registerCheck<MutatorAndToOr>("mutator-and-to-or");
                CheckFactories.registerCheck<MutatorOrToAnd>("mutator-or-to-and");
                CheckFactories.registerCheck<MutatorReverseIfCond>("mutator-reverse-if-cond");
                CheckFactories.registerCheck<MutatorEqToNeq>("mutator-eq-to-neq");
                CheckFactories.registerCheck<MutatorNeqToEq>("mutator-neq-to-eq");
                CheckFactories.registerCheck<MutatorTrueToFalse>("mutator-true-to-false");
                CheckFactories.registerCheck<MutatorFalseToTrue>("mutator-false-to-true");
                CheckFactories.registerCheck<MutatorGreaterToLess>("mutator-greater-to-less");
                CheckFactories.registerCheck<MutatorLessToGreater>("mutator-less-to-greater");
                CheckFactories.registerCheck<MutatorGreaterEqToLessEq>("mutator-greater-eq-to-less-eq");
                CheckFactories.registerCheck<MutatorLessEqToGreaterEq>("mutator-less-eq-to-greater-eq");
            }
        };

        // Register the ReadabilityModule using this statically initialized variable.
        static ClangTidyModuleRegistry::Add<MutatorModule> X("mutator-module", "Adds mutators.");

    }  // namespace mutator

    // This anchor is used to force the linker to link in the generated object file
    // and thus register the ReadabilityModule.
    volatile int MutatorModuleAnchorSource = 0;

}  // namespace clang::tidy
