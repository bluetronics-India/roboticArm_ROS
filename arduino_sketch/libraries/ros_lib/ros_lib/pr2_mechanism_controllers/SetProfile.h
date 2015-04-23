#ifndef _ROS_SERVICE_SetProfile_h
#define _ROS_SERVICE_SetProfile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_mechanism_controllers
{

static const char SETPROFILE[] = "pr2_mechanism_controllers/SetProfile";

  class SetProfileRequest : public ros::Msg
  {
    public:
      float UpperTurnaround;
      float LowerTurnaround;
      float upperDecelBuffer;
      float lowerDecelBuffer;
      float profile;
      float period;
      float amplitude;
      float offset;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->UpperTurnaround);
      offset += serializeAvrFloat64(outbuffer + offset, this->LowerTurnaround);
      offset += serializeAvrFloat64(outbuffer + offset, this->upperDecelBuffer);
      offset += serializeAvrFloat64(outbuffer + offset, this->lowerDecelBuffer);
      offset += serializeAvrFloat64(outbuffer + offset, this->profile);
      offset += serializeAvrFloat64(outbuffer + offset, this->period);
      offset += serializeAvrFloat64(outbuffer + offset, this->amplitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->UpperTurnaround));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->LowerTurnaround));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->upperDecelBuffer));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lowerDecelBuffer));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->profile));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->amplitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->offset));
     return offset;
    }

    const char * getType(){ return SETPROFILE; };
    const char * getMD5(){ return "309001fc196b0094f23b1ae2bd672fb2"; };

  };

  class SetProfileResponse : public ros::Msg
  {
    public:
      float time;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
     return offset;
    }

    const char * getType(){ return SETPROFILE; };
    const char * getMD5(){ return "be5310e7aa4c90cdee120add91648cee"; };

  };

  class SetProfile {
    public:
    typedef SetProfileRequest Request;
    typedef SetProfileResponse Response;
  };

}
#endif
