// Generated by gencpp from file robotnik_msgs/SafetyModuleStatus.msg
// DO NOT EDIT!


#ifndef ROBOTNIK_MSGS_MESSAGE_SAFETYMODULESTATUS_H
#define ROBOTNIK_MSGS_MESSAGE_SAFETYMODULESTATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <robotnik_msgs/LaserMode.h>
#include <robotnik_msgs/LaserStatus.h>

namespace robotnik_msgs
{
template <class ContainerAllocator>
struct SafetyModuleStatus_
{
  typedef SafetyModuleStatus_<ContainerAllocator> Type;

  SafetyModuleStatus_()
    : safety_mode()
    , charging(false)
    , emergency_stop(false)
    , safety_stop(false)
    , safety_overrided(false)
    , lasers_on_standby(false)
    , current_speed(0.0)
    , speed_at_safety_stop(0.0)
    , lasers_mode()
    , lasers_status()  {
    }
  SafetyModuleStatus_(const ContainerAllocator& _alloc)
    : safety_mode(_alloc)
    , charging(false)
    , emergency_stop(false)
    , safety_stop(false)
    , safety_overrided(false)
    , lasers_on_standby(false)
    , current_speed(0.0)
    , speed_at_safety_stop(0.0)
    , lasers_mode(_alloc)
    , lasers_status(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _safety_mode_type;
  _safety_mode_type safety_mode;

   typedef uint8_t _charging_type;
  _charging_type charging;

   typedef uint8_t _emergency_stop_type;
  _emergency_stop_type emergency_stop;

   typedef uint8_t _safety_stop_type;
  _safety_stop_type safety_stop;

   typedef uint8_t _safety_overrided_type;
  _safety_overrided_type safety_overrided;

   typedef uint8_t _lasers_on_standby_type;
  _lasers_on_standby_type lasers_on_standby;

   typedef double _current_speed_type;
  _current_speed_type current_speed;

   typedef double _speed_at_safety_stop_type;
  _speed_at_safety_stop_type speed_at_safety_stop;

   typedef  ::robotnik_msgs::LaserMode_<ContainerAllocator>  _lasers_mode_type;
  _lasers_mode_type lasers_mode;

   typedef std::vector< ::robotnik_msgs::LaserStatus_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::robotnik_msgs::LaserStatus_<ContainerAllocator> >> _lasers_status_type;
  _lasers_status_type lasers_status;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(SAFE)
  #undef SAFE
#endif
#if defined(_WIN32) && defined(OVERRIDABLE)
  #undef OVERRIDABLE
#endif
#if defined(_WIN32) && defined(EMERGENCY)
  #undef EMERGENCY
#endif
#if defined(_WIN32) && defined(LASER_MUTE)
  #undef LASER_MUTE
#endif


  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SAFE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> OVERRIDABLE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMERGENCY;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> LASER_MUTE;

  typedef boost::shared_ptr< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> const> ConstPtr;

}; // struct SafetyModuleStatus_

typedef ::robotnik_msgs::SafetyModuleStatus_<std::allocator<void> > SafetyModuleStatus;

typedef boost::shared_ptr< ::robotnik_msgs::SafetyModuleStatus > SafetyModuleStatusPtr;
typedef boost::shared_ptr< ::robotnik_msgs::SafetyModuleStatus const> SafetyModuleStatusConstPtr;

// constants requiring out of line definition

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      SafetyModuleStatus_<ContainerAllocator>::SAFE =
        
          "safe"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      SafetyModuleStatus_<ContainerAllocator>::OVERRIDABLE =
        
          "overridable"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      SafetyModuleStatus_<ContainerAllocator>::EMERGENCY =
        
          "emergency"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      SafetyModuleStatus_<ContainerAllocator>::LASER_MUTE =
        
          "laser_mute"
        
        ;
   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator1> & lhs, const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator2> & rhs)
{
  return lhs.safety_mode == rhs.safety_mode &&
    lhs.charging == rhs.charging &&
    lhs.emergency_stop == rhs.emergency_stop &&
    lhs.safety_stop == rhs.safety_stop &&
    lhs.safety_overrided == rhs.safety_overrided &&
    lhs.lasers_on_standby == rhs.lasers_on_standby &&
    lhs.current_speed == rhs.current_speed &&
    lhs.speed_at_safety_stop == rhs.speed_at_safety_stop &&
    lhs.lasers_mode == rhs.lasers_mode &&
    lhs.lasers_status == rhs.lasers_status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator1> & lhs, const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robotnik_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3cc2546ca0e4e9e66c091e756e7d22d7";
  }

  static const char* value(const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3cc2546ca0e4e9e6ULL;
  static const uint64_t static_value2 = 0x6c091e756e7d22d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotnik_msgs/SafetyModuleStatus";
  }

  static const char* value(const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# robot safety mode\n"
"string SAFE=safe\n"
"string OVERRIDABLE=overridable\n"
"string EMERGENCY=emergency\n"
"string LASER_MUTE=laser_mute\n"
"\n"
"string safety_mode\n"
"bool charging\n"
"bool emergency_stop        # if e-stop is pressed\n"
"bool safety_stop           # if system is stopped due to safety system\n"
"bool safety_overrided      # if safety system is overrided\n"
"bool lasers_on_standby     # if lasers don't have power\n"
"float64 current_speed       # current speed measured by safety system\n"
"float64 speed_at_safety_stop  # speed measured at last safety stop by safety system\n"
"\n"
"robotnik_msgs/LaserMode lasers_mode\n"
"robotnik_msgs/LaserStatus[] lasers_status\n"
"\n"
"================================================================================\n"
"MSG: robotnik_msgs/LaserMode\n"
"string STANDARD=standard\n"
"string DOCKING_STATION=docking_station\n"
"string CART=cart\n"
"string CART_DOCKING_CART=cart_docking_cart\n"
"string DOCKING_CART=docking_cart\n"
"string INVALID=invalid\n"
"\n"
"string name\n"
"\n"
"================================================================================\n"
"MSG: robotnik_msgs/LaserStatus\n"
"string name\n"
"bool detecting_obstacles\n"
"bool contaminated\n"
"bool free_warning\n"
"# one input per each warning zone.\n"
"# first areas are closer to the robot (i.e. more restrictive)\n"
"bool[] warning_zones \n"
;
  }

  static const char* value(const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.safety_mode);
      stream.next(m.charging);
      stream.next(m.emergency_stop);
      stream.next(m.safety_stop);
      stream.next(m.safety_overrided);
      stream.next(m.lasers_on_standby);
      stream.next(m.current_speed);
      stream.next(m.speed_at_safety_stop);
      stream.next(m.lasers_mode);
      stream.next(m.lasers_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SafetyModuleStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotnik_msgs::SafetyModuleStatus_<ContainerAllocator>& v)
  {
    s << indent << "safety_mode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.safety_mode);
    s << indent << "charging: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.charging);
    s << indent << "emergency_stop: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.emergency_stop);
    s << indent << "safety_stop: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.safety_stop);
    s << indent << "safety_overrided: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.safety_overrided);
    s << indent << "lasers_on_standby: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.lasers_on_standby);
    s << indent << "current_speed: ";
    Printer<double>::stream(s, indent + "  ", v.current_speed);
    s << indent << "speed_at_safety_stop: ";
    Printer<double>::stream(s, indent + "  ", v.speed_at_safety_stop);
    s << indent << "lasers_mode: ";
    s << std::endl;
    Printer< ::robotnik_msgs::LaserMode_<ContainerAllocator> >::stream(s, indent + "  ", v.lasers_mode);
    s << indent << "lasers_status[]" << std::endl;
    for (size_t i = 0; i < v.lasers_status.size(); ++i)
    {
      s << indent << "  lasers_status[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::robotnik_msgs::LaserStatus_<ContainerAllocator> >::stream(s, indent + "    ", v.lasers_status[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTNIK_MSGS_MESSAGE_SAFETYMODULESTATUS_H
