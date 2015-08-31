//===-- MachOUtils.h - Mach-o specific helpers for dsymutil  --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H
#define LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H

#include <string>
#include "llvm/ADT/StringRef.h"

namespace llvm {
namespace dsymutil {
struct LinkOptions;
namespace MachOUtils {

struct ArchAndFilename {
  std::string Arch, Path;
  ArchAndFilename(StringRef Arch, StringRef Path) : Arch(Arch), Path(Path) {}
};

bool generateUniversalBinary(SmallVectorImpl<ArchAndFilename> &ArchFiles,
                             StringRef OutputFileName, const LinkOptions &);

std::string getArchName(StringRef Arch);
}
}
}
#endif // LLVM_TOOLS_DSYMUTIL_MACHOUTILS_H