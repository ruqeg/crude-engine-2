#include <platform/platform_components.h>

ECS_COMPONENT_DECLARE( crude_input );
ECS_COMPONENT_DECLARE( crude_window );
ECS_COMPONENT_DECLARE( crude_window_handle );

void
crude_platform_componentsImport
(
  ecs_world_t *world
)
{
  ECS_MODULE( world, crude_platform_components );
  ECS_COMPONENT_DEFINE( world, crude_input );
  ECS_COMPONENT_DEFINE( world, crude_window );
  ECS_COMPONENT_DEFINE( world, crude_window_handle );
  
  ecs_struct_init(world, &(ecs_struct_desc_t){
    .entity  = ecs_id( crude_window ),
    .members = {
      { .name = "width", .type = ecs_id( ecs_i32_t ) },
      { .name = "height", .type = ecs_id( ecs_i32_t ) },
      { .name = "maximized", .type = ecs_id( ecs_bool_t ) 
    } } } );
  
  ecs_struct_init(world, &( ecs_struct_desc_t ){
    .entity  = ecs_id( crude_window_handle ),
    .members = {
      { .name = "value", .type = sizeof( void * ) == 4 ? ecs_id( ecs_i32_t ) : ecs_id( ecs_i64_t ) }
    } } );
}