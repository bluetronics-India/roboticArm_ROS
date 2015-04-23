#ifndef _ROS_pr2_controllers_msgs_PointHeadFeedback_h
#define _ROS_pr2_controllers_msgs_PointHeadFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_controllers_msgs
{

  class PointHeadFeedback : public ros::Msg
  {
    public:
      float pointing_angle_error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->pointing_angle_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pointing_angle_error));
     return offset;
    }

    const char * getType(){ return "pr2_controllers_msgs/PointHeadFeedback"; };
    const char * getMD5(){ return "cce80d27fd763682da8805a73316cab4"; };

  };

}
#endif