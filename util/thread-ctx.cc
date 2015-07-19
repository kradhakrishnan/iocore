#include "thread-ctx.h"

using namespace bblocks;

//
// ThreadCtx
//

__thread Thread * ThreadCtx::tinst_;
__thread list<uint8_t *> * ThreadCtx::pool_;

string ThreadCtx::log_("/threadctx");
PerfCounter ThreadCtx::statGC_("/threadctx/gc", "B", PerfCounter::BYTES);
PerfCounter ThreadCtx::statHits_("/threadctx/alloc", "hits", PerfCounter::COUNTER);


