﻿///
/// Copyright (c) 2009-2014 Nous Xiong (348944179 at qq dot com)
///
/// Distributed under the Boost Software License, Version 1.0. (See accompanying
/// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///
/// See https://github.com/nousxiong/gce for latest version.
///

#ifndef GCE_ACTOR_SERVICE_HPP
#define GCE_ACTOR_SERVICE_HPP

#include <gce/actor/config.hpp>
#include <gce/actor/coroutine_stackfull_actor.hpp>
#include <gce/actor/detail/cache_pool.hpp>
#include <gce/actor/service_id.hpp>

namespace gce
{
inline void register_service(self_t self, match_t name)
{
  detail::cache_pool* user = self.get_cache_pool();
  context& ctx = user->get_context();
  user->register_service(name, self.get_aid());
  ctx.register_service(name, self.get_aid(), user->get_index());
}

inline void deregister_service(self_t self, match_t name)
{
  detail::cache_pool* user = self.get_cache_pool();
  context& ctx = user->get_context();
  user->deregister_service(name, self.get_aid());
  ctx.deregister_service(name, self.get_aid(), user->get_index());
}
}

#endif /// GCE_ACTOR_SERVICE_HPP
