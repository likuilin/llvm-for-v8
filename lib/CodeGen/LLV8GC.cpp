/*
 * llvm-gc-strategy.cc
 *
 *  Created on: Sep 14, 2015
 *      Author: vlad
 */

#include "llvm/CodeGen/GCs.h"
#include "llvm/CodeGen/GCStrategy.h"
//#include "llvm/IR/DerivedTypes.h"
//#include "llvm/IR/Value.h"

namespace {

class LLV8GC : public llvm::GCStrategy {
public:
  LLV8GC() {
    UseStatepoints = true;
    // These options are all gc.root specific, we specify them so that the
    // gc.root lowering code doesn't run.
    InitRoots = false;
    NeededSafePoints = 0;
    UsesMetadata = false;
    CustomRoots = false;
  }
  llvm::Optional<bool> isGCManagedPointer(const llvm::Value *V) const override {
    return true;
  }
};

} // namespace

static llvm::GCRegistry::Add<LLV8GC> X("v8-gc", "Dummy GC strategy for V8");

namespace llvm {
void linkLLV8GC() {}
}
