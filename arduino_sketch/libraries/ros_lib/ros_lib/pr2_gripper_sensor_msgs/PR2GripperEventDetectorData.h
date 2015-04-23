#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperEventDetectorData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperEventDetectorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperEventDetectorData : public ros::Msg
  {
    public:
      ros::Time stamp;
      bool trigger_conditions_met;
      bool slip_event;
      bool acceleration_event;
      float acceleration_vector[3];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      union {
        bool real;
        uint8_t base;
      } u_trigger_conditions_met;
      u_trigger_conditions_met.real = this->trigger_conditions_met;
      *(outbuffer + offset + 0) = (u_trigger_conditions_met.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trigger_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_slip_event;
      u_slip_event.real = this->slip_event;
      *(outbuffer + offset + 0) = (u_slip_event.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->slip_event);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_event;
      u_acceleration_event.real = this->acceleration_event;
      *(outbuffer + offset + 0) = (u_acceleration_event.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->acceleration_event);
      for( uint8_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration_vector[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      union {
        bool real;
        uint8_t base;
      } u_trigger_conditions_met;
      u_trigger_conditions_met.base = 0;
      u_trigger_conditions_met.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trigger_conditions_met = u_trigger_conditions_met.real;
      offset += sizeof(this->trigger_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_slip_event;
      u_slip_event.base = 0;
      u_slip_event.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->slip_event = u_slip_event.real;
      offset += sizeof(this->slip_event);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_event;
      u_acceleration_event.base = 0;
      u_acceleration_event.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->acceleration_event = u_acceleration_event.real;
      offset += sizeof(this->acceleration_event);
      for( uint8_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration_vector[i]));
      }
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperEventDetectorData"; };
    const char * getMD5(){ return "9536d682ef6215440ecc47846d4117c2"; };

  };

}
#endif