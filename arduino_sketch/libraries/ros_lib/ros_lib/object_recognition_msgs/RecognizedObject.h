#ifndef _ROS_object_recognition_msgs_RecognizedObject_h
#define _ROS_object_recognition_msgs_RecognizedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/ObjectType.h"
#include "sensor_msgs/PointCloud2.h"
#include "shape_msgs/Mesh.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace object_recognition_msgs
{

  class RecognizedObject : public ros::Msg
  {
    public:
      std_msgs::Header header;
      object_recognition_msgs::ObjectType type;
      float confidence;
      uint8_t point_clouds_length;
      sensor_msgs::PointCloud2 st_point_clouds;
      sensor_msgs::PointCloud2 * point_clouds;
      shape_msgs::Mesh bounding_mesh;
      uint8_t bounding_contours_length;
      geometry_msgs::Point st_bounding_contours;
      geometry_msgs::Point * bounding_contours;
      geometry_msgs::PoseWithCovarianceStamped pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->type.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      *(outbuffer + offset++) = point_clouds_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < point_clouds_length; i++){
      offset += this->point_clouds[i].serialize(outbuffer + offset);
      }
      offset += this->bounding_mesh.serialize(outbuffer + offset);
      *(outbuffer + offset++) = bounding_contours_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bounding_contours_length; i++){
      offset += this->bounding_contours[i].serialize(outbuffer + offset);
      }
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->type.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      uint8_t point_clouds_lengthT = *(inbuffer + offset++);
      if(point_clouds_lengthT > point_clouds_length)
        this->point_clouds = (sensor_msgs::PointCloud2*)realloc(this->point_clouds, point_clouds_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      point_clouds_length = point_clouds_lengthT;
      for( uint8_t i = 0; i < point_clouds_length; i++){
      offset += this->st_point_clouds.deserialize(inbuffer + offset);
        memcpy( &(this->point_clouds[i]), &(this->st_point_clouds), sizeof(sensor_msgs::PointCloud2));
      }
      offset += this->bounding_mesh.deserialize(inbuffer + offset);
      uint8_t bounding_contours_lengthT = *(inbuffer + offset++);
      if(bounding_contours_lengthT > bounding_contours_length)
        this->bounding_contours = (geometry_msgs::Point*)realloc(this->bounding_contours, bounding_contours_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      bounding_contours_length = bounding_contours_lengthT;
      for( uint8_t i = 0; i < bounding_contours_length; i++){
      offset += this->st_bounding_contours.deserialize(inbuffer + offset);
        memcpy( &(this->bounding_contours[i]), &(this->st_bounding_contours), sizeof(geometry_msgs::Point));
      }
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/RecognizedObject"; };
    const char * getMD5(){ return "f92c4cb29ba11f26c5f7219de97e900d"; };

  };

}
#endif