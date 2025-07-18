#pragma once

#include <core/ecs.h>
#include <core/memory.h>
#include <core/string.h>

typedef struct crude_scene_creation
{
  ecs_world_t                                             *world;
  crude_entity                                             input_entity;
  char const                                              *resources_path;
  crude_stack_allocator                                   *temporary_allocator;
  crude_allocator_container                                allocator_container;
} crude_scene_creation;

typedef struct crude_scene
{
  ecs_world_t                                             *world;
  crude_entity                                            *nodes;
  crude_entity                                             main_node;
  crude_entity                                             main_camera;
  crude_entity                                             debug_camera;
  char                                                    *resources_path;
  crude_allocator_container                                allocator_container;
  crude_stack_allocator                                   *temporary_allocator;
  crude_string_buffer                                      path_bufffer;
  crude_entity                                             input_entity;
} crude_scene;

CRUDE_API void
crude_scene_initialize
(
  _In_ crude_scene                                        *scene,
  _In_ crude_scene_creation const                         *creation
);

CRUDE_API void
crude_scene_deinitialize
(
  _In_ crude_scene                                        *scene
);

CRUDE_API void
crude_scene_load
(
  _In_ crude_scene                                        *scene,
  _In_ char const                                         *json_name
);