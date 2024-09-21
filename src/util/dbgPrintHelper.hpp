#ifndef DBGPRINTHELPER_HPP
#define DBGPRINTHELPER_HPP

//If we are producing a release, then no debug message will be printed at all,
//independently of the debug level chosen: all the debug instructions are evicted
//from the code, thus speeding up the execution.
#ifdef NDEBUG

///We are producing a release, no debug message is printed: in order to enable the production
///of the release, just use CXXFLAGS="-DNDEBUG -DNOUTPUT"
#define LOG_TRACE(mex) void (0)
#define LOG_DEBUG(mex) void (0)
#define LOG_INFO(mex) void (0)
#define LOG_WARNING(mex) void (0)
#define LOG_ERROR(mex) void (0)
#define LOG_FATAL(mex) void (0)
    
#else // NDEBUG

#include <boost/log/trivial.hpp>

#define LOG_TRACE(mex) \
   BOOST_LOG_TRIVIAL(trace) << mex

#define LOG_DEBUG(mex) \
   BOOST_LOG_TRIVIAL(debug) << mex

#define LOG_INFO(mex) \
   BOOST_LOG_TRIVIAL(info) << mex

#define LOG_WARNING(mex) \
   BOOST_LOG_TRIVIAL(warning) << mex

#define LOG_ERROR(mex) \
   BOOST_LOG_TRIVIAL(error) << mex

#define LOG_FATAL(mex) \
   BOOST_LOG_TRIVIAL(fatal) << mex

#endif // NDEBUG
#endif // DBGPRINTHELPER_HPP
