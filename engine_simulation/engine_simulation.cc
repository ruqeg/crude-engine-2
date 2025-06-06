#include <engine.h>
#include <cr/cr.h>
#include <assert.h>

CR_EXPORT int
cr_main
(
  struct cr_plugin                                        *ctx,
  enum cr_op                                               operation
)
{
  assert( ctx );
  if ( operation == CR_STEP )
  {
    crude_engine_update( ( crude_engine* )ctx->userdata );
  }
  return 0;
}
