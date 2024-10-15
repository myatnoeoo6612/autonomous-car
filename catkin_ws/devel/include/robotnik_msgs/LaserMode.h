// Generated by gencpp from file robotnik_msgs/LaserMode.msg
// DO NOT EDIT!


#ifndef ROBOTNIK_MSGS_MESSAGE_LASERMODE_H
#define ROBOTNIK_MSGS_MESSAGE_LASERMODE_H


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
struct LaserMode_
{
  typedef LaserMode_<ContainerAllocator> Type;

  LaserMode_()
    : name()  {
    }
  LaserMode_(const ContainerAllocator& _alloc)
    : name(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(STANDARD)
  #undef STANDARD
#endif
#if defined(_WIN32) && defined(DOCKING_STATION)
  #undef DOCKING_STATION
#endif
#if defined(_WIN32) && defined(CART)
  #undef CART
#endif
#if defined(_WIN32) && defined(CART_DOCKING_CART)
  #undef CART_DOCKING_CART
#endif
#if defined(_WIN32) && defined(DOCKING_CART)
  #undef DOCKING_CART
#endif
#if defined(_WIN32) && defined(INVALID)
  #undef INVALID
#endif


  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> STANDARD;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DOCKING_STATION;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> CART;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> CART_DOCKING_CART;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DOCKING_CART;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> INVALID;

  typedef boost::shared_ptr< ::robotnik_msgs::LaserMode_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotnik_msgs::LaserMode_<ContainerAllocator> const> ConstPtr;

}; // struct LaserMode_

typedef ::robotnik_msgs::LaserMode_<std::allocator<void> > LaserMode;

typedef boost::shared_ptr< ::robotnik_msgs::LaserMode > LaserModePtr;
typedef boost::shared_ptr< ::robotnik_msgs::LaserMode const> LaserModeConstPtr;

// constants requiring out of line definition

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::STANDARD =
        
          "standard"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::DOCKING_STATION =
        
          "docking_station"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::CART =
        
          "cart"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::CART_DOCKING_CART =
        
          "cart_docking_cart"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::DOCKING_CART =
        
          "docking_cart"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      LaserMode_<ContainerAllocator>::INVALID =
        
          "invalid"
        
        ;
   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotnik_msgs::LaserMode_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotnik_msgs::LaserMode_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robotnik_msgs::LaserMode_<ContainerAllocator1> & lhs, const ::robotnik_msgs::LaserMode_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robotnik_msgs::LaserMode_<ContainerAllocator1> & lhs, const ::robotnik_msgs::LaserMode_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robotnik_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::LaserMode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::LaserMode_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::LaserMode_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6d9ec22e8c4a4279a8a61cc162391fee";
  }

  static const char* value(const ::robotnik_msgs::LaserMode_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6d9ec22e8c4a4279ULL;
  static const uint64_t static_value2 = 0xa8a61cc162391feeULL;
};

template<class ContainerAllocator>
struct DataType< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotnik_msgs/LaserMode";
  }

  static const char* value(const ::robotnik_msgs::LaserMode_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string STANDARD=standard\n"
"string DOCKING_STATION=docking_station\n"
"string CART=cart\n"
"string CART_DOCKING_CART=cart_docking_cart\n"
"string DOCKING_CART=docking_cart\n"
"string INVALID=invalid\n"
"\n"
"string name\n"
;
  }

  static const char* value(const ::robotnik_msgs::LaserMode_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LaserMode_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotnik_msgs::LaserMode_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotnik_msgs::LaserMode_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTNIK_MSGS_MESSAGE_LASERMODE_H
