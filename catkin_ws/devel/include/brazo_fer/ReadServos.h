// Generated by gencpp from file brazo_fer/ReadServos.msg
// DO NOT EDIT!


#ifndef BRAZO_FER_MESSAGE_READSERVOS_H
#define BRAZO_FER_MESSAGE_READSERVOS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <brazo_fer/Servos.h>
#include <brazo_fer/Servos.h>
#include <brazo_fer/Servos.h>

namespace brazo_fer
{
template <class ContainerAllocator>
struct ReadServos_
{
  typedef ReadServos_<ContainerAllocator> Type;

  ReadServos_()
    : posicion()
    , estado()
    , corriente()  {
    }
  ReadServos_(const ContainerAllocator& _alloc)
    : posicion(_alloc)
    , estado(_alloc)
    , corriente(_alloc)  {
    }



   typedef  ::brazo_fer::Servos_<ContainerAllocator>  _posicion_type;
  _posicion_type posicion;

   typedef  ::brazo_fer::Servos_<ContainerAllocator>  _estado_type;
  _estado_type estado;

   typedef  ::brazo_fer::Servos_<ContainerAllocator>  _corriente_type;
  _corriente_type corriente;




  typedef boost::shared_ptr< ::brazo_fer::ReadServos_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::brazo_fer::ReadServos_<ContainerAllocator> const> ConstPtr;

}; // struct ReadServos_

typedef ::brazo_fer::ReadServos_<std::allocator<void> > ReadServos;

typedef boost::shared_ptr< ::brazo_fer::ReadServos > ReadServosPtr;
typedef boost::shared_ptr< ::brazo_fer::ReadServos const> ReadServosConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::brazo_fer::ReadServos_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::brazo_fer::ReadServos_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace brazo_fer

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'brazo_fer': ['/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::brazo_fer::ReadServos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::brazo_fer::ReadServos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::brazo_fer::ReadServos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::brazo_fer::ReadServos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::brazo_fer::ReadServos_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::brazo_fer::ReadServos_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::brazo_fer::ReadServos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eb601df5ba86278a5ceaf5eea9e7da64";
  }

  static const char* value(const ::brazo_fer::ReadServos_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeb601df5ba86278aULL;
  static const uint64_t static_value2 = 0x5ceaf5eea9e7da64ULL;
};

template<class ContainerAllocator>
struct DataType< ::brazo_fer::ReadServos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "brazo_fer/ReadServos";
  }

  static const char* value(const ::brazo_fer::ReadServos_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::brazo_fer::ReadServos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Servos posicion\n\
Servos estado\n\
Servos corriente\n\
\n\
================================================================================\n\
MSG: brazo_fer/Servos\n\
int16 base\n\
int16 arti1\n\
int16 arti2\n\
int16 arti3\n\
int16 pinza\n\
";
  }

  static const char* value(const ::brazo_fer::ReadServos_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::brazo_fer::ReadServos_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.posicion);
      stream.next(m.estado);
      stream.next(m.corriente);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ReadServos_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::brazo_fer::ReadServos_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::brazo_fer::ReadServos_<ContainerAllocator>& v)
  {
    s << indent << "posicion: ";
    s << std::endl;
    Printer< ::brazo_fer::Servos_<ContainerAllocator> >::stream(s, indent + "  ", v.posicion);
    s << indent << "estado: ";
    s << std::endl;
    Printer< ::brazo_fer::Servos_<ContainerAllocator> >::stream(s, indent + "  ", v.estado);
    s << indent << "corriente: ";
    s << std::endl;
    Printer< ::brazo_fer::Servos_<ContainerAllocator> >::stream(s, indent + "  ", v.corriente);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BRAZO_FER_MESSAGE_READSERVOS_H
