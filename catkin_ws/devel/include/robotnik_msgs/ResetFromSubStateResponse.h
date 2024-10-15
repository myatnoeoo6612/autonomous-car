// Generated by gencpp from file robotnik_msgs/ResetFromSubStateResponse.msg
// DO NOT EDIT!


#ifndef ROBOTNIK_MSGS_MESSAGE_RESETFROMSUBSTATERESPONSE_H
#define ROBOTNIK_MSGS_MESSAGE_RESETFROMSUBSTATERESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotnik_msgs
{
template <class ContainerAllocator>
struct ResetFromSubStateResponse_
{
  typedef ResetFromSubStateResponse_<ContainerAllocator> Type;

  ResetFromSubStateResponse_()
    : currentSubState(0)
    , success(false)
    , msg()  {
    }
  ResetFromSubStateResponse_(const ContainerAllocator& _alloc)
    : currentSubState(0)
    , success(false)
    , msg(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _currentSubState_type;
  _currentSubState_type currentSubState;

   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _msg_type;
  _msg_type msg;





  typedef boost::shared_ptr< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ResetFromSubStateResponse_

typedef ::robotnik_msgs::ResetFromSubStateResponse_<std::allocator<void> > ResetFromSubStateResponse;

typedef boost::shared_ptr< ::robotnik_msgs::ResetFromSubStateResponse > ResetFromSubStateResponsePtr;
typedef boost::shared_ptr< ::robotnik_msgs::ResetFromSubStateResponse const> ResetFromSubStateResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator1> & lhs, const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator2> & rhs)
{
  return lhs.currentSubState == rhs.currentSubState &&
    lhs.success == rhs.success &&
    lhs.msg == rhs.msg;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator1> & lhs, const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robotnik_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "29ac8b3c219a9c9ea312264e17cdc11f";
  }

  static const char* value(const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x29ac8b3c219a9c9eULL;
  static const uint64_t static_value2 = 0xa312264e17cdc11fULL;
};

template<class ContainerAllocator>
struct DataType< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotnik_msgs/ResetFromSubStateResponse";
  }

  static const char* value(const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# substate of the component when change\n"
"int32 currentSubState\n"
"\n"
"# The change is correct\n"
"bool success\n"
"\n"
"# Text message - additional status information\n"
"string msg\n"
"\n"
;
  }

  static const char* value(const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.currentSubState);
      stream.next(m.success);
      stream.next(m.msg);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ResetFromSubStateResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotnik_msgs::ResetFromSubStateResponse_<ContainerAllocator>& v)
  {
    s << indent << "currentSubState: ";
    Printer<int32_t>::stream(s, indent + "  ", v.currentSubState);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "msg: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.msg);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTNIK_MSGS_MESSAGE_RESETFROMSUBSTATERESPONSE_H
