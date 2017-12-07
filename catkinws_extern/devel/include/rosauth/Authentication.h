// Generated by gencpp from file rosauth/Authentication.msg
// DO NOT EDIT!


#ifndef ROSAUTH_MESSAGE_AUTHENTICATION_H
#define ROSAUTH_MESSAGE_AUTHENTICATION_H

#include <ros/service_traits.h>


#include <rosauth/AuthenticationRequest.h>
#include <rosauth/AuthenticationResponse.h>


namespace rosauth
{

struct Authentication
{

typedef AuthenticationRequest Request;
typedef AuthenticationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Authentication
} // namespace rosauth


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rosauth::Authentication > {
  static const char* value()
  {
    return "0297b5bdd9c066699bfaf0157aad17e7";
  }

  static const char* value(const ::rosauth::Authentication&) { return value(); }
};

template<>
struct DataType< ::rosauth::Authentication > {
  static const char* value()
  {
    return "rosauth/Authentication";
  }

  static const char* value(const ::rosauth::Authentication&) { return value(); }
};


// service_traits::MD5Sum< ::rosauth::AuthenticationRequest> should match 
// service_traits::MD5Sum< ::rosauth::Authentication > 
template<>
struct MD5Sum< ::rosauth::AuthenticationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rosauth::Authentication >::value();
  }
  static const char* value(const ::rosauth::AuthenticationRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosauth::AuthenticationRequest> should match 
// service_traits::DataType< ::rosauth::Authentication > 
template<>
struct DataType< ::rosauth::AuthenticationRequest>
{
  static const char* value()
  {
    return DataType< ::rosauth::Authentication >::value();
  }
  static const char* value(const ::rosauth::AuthenticationRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rosauth::AuthenticationResponse> should match 
// service_traits::MD5Sum< ::rosauth::Authentication > 
template<>
struct MD5Sum< ::rosauth::AuthenticationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rosauth::Authentication >::value();
  }
  static const char* value(const ::rosauth::AuthenticationResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosauth::AuthenticationResponse> should match 
// service_traits::DataType< ::rosauth::Authentication > 
template<>
struct DataType< ::rosauth::AuthenticationResponse>
{
  static const char* value()
  {
    return DataType< ::rosauth::Authentication >::value();
  }
  static const char* value(const ::rosauth::AuthenticationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROSAUTH_MESSAGE_AUTHENTICATION_H
