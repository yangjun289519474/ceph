// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab

#ifndef CEPH_LIBRBD_API_GROUP_H
#define CEPH_LIBRBD_API_GROUP_H

#include "include/rbd/librbd.hpp"
#include <string>
#include <vector>

namespace librados { struct IoCtx; }

namespace librbd {

struct ImageCtx;

namespace api {

template <typename ImageCtxT = librbd::ImageCtx>
struct Group {

  static int create(librados::IoCtx& io_ctx, const char *imgname);
  static int remove(librados::IoCtx& io_ctx, const char *group_name);
  static int list(librados::IoCtx& io_ctx, std::vector<std::string> *names);

  static int image_add(librados::IoCtx& group_ioctx, const char *group_name,
		       librados::IoCtx& image_ioctx, const char *image_name);
  static int image_remove(librados::IoCtx& group_ioctx, const char *group_name,
		          librados::IoCtx& image_ioctx, const char *image_name);
  static int image_remove_by_id(librados::IoCtx& group_ioctx,
                                const char *group_name,
                                librados::IoCtx& image_ioctx,
                                const char *image_id);
  static int image_list(librados::IoCtx& group_ioctx, const char *group_name,
		        std::vector<group_image_status_t> *images);

  static int image_get_group(ImageCtxT *ictx, group_spec_t *group_spec);

};

} // namespace api
} // namespace librbd

extern template class librbd::api::Group<librbd::ImageCtx>;

#endif // CEPH_LIBRBD_API_GROUP_H
