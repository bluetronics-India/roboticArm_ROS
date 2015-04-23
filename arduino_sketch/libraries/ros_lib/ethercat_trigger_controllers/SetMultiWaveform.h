#ifndef _ROS_SERVICE_SetMultiWaveform_h
#define _ROS_SERVICE_SetMultiWaveform_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ethercat_trigger_controllers/MultiWaveform.h"

namespace ethercat_trigger_controllers
{

static const char SETMULTIWAVEFORM[] = "ethercat_trigger_controllers/SetMultiWaveform";

  class SetMultiWaveformRequest : public ros::Msg
  {
    public:
      ethercat_trigger_controllers::MultiWaveform waveform;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->waveform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->waveform.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETMULTIWAVEFORM; };
    const char * getMD5(){ return "bfedad8205348a9bcc90e6ae4b778d86"; };

  };

  class SetMultiWaveformResponse : public ros::Msg
  {
    public:
      bool success;
      const char* status_message;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      memcpy(outbuffer + offset, &length_status_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      memcpy(&length_status_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    const char * getType(){ return SETMULTIWAVEFORM; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetMultiWaveform {
    public:
    typedef SetMultiWaveformRequest Request;
    typedef SetMultiWaveformResponse Response;
  };

}
#endif
