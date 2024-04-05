#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/DataLayout.h"
#include<bits/stdc++.h>
#define threshold 5

using namespace llvm;
using namespace std;

namespace {

struct MemoryUsagePass : public ModulePass {
  static char ID; // Pass identification, replacement for typeid
  int BBId=1;
  MemoryUsagePass() : ModulePass(ID) {}

  bool runOnModule(Module &M) override {
    for (auto &F : M) {
      if (!F.isDeclaration()) {
        //errs() << "Function: " << F.getName() << "\n";
        size_t functionMemoryUsage = 0;
        // vector<string>BBIds; 
        int firstBBId=BBId;
        for (auto &BB : F) {
          //string temp = BB.getName().str();
          //BBIds.push_back(temp);
          BBId++;
          for (auto &I : BB) {
            if (AllocaInst *AI = dyn_cast<AllocaInst>(&I)) {
              // Retrieve the allocated type
              Type *AllocatedType = AI->getAllocatedType();
              if (AllocatedType) {
                functionMemoryUsage += M.getDataLayout().getTypeAllocSize(AllocatedType);
              }
            }
          }
        }
        if(functionMemoryUsage >= threshold){
          // errs() << "Basic Blocks: \n";
          errs() << "Function: " << F.getName() << "\n";
          errs() << "Memory Usage: " << functionMemoryUsage << " bytes\n";
          // Printing basic block IDs
          errs() << " Basic Block ID: " << firstBBId<< "\n";
        errs()<<"\n---------------------------------------------------------------------------------------------------\n";
        }
      }
      //errs()<<"\n";
    }
    return false;
  }
};

} // anonymous namespace

char MemoryUsagePass::ID = 0;

// Register the pass with LLVM so it can be invoked by opt
static RegisterPass<MemoryUsagePass> X("memory-usage", "Memory Usage Pass", false, false);
