--- luabind/object.hpp.orig	2010-08-31 13:24:52 UTC
+++ luabind/object.hpp
@@ -536,6 +536,7 @@ namespace detail
       handle m_key;
   };
 
+#if BOOST_VERSION < 105700
 // Needed because of some strange ADL issues.
 
 #define LUABIND_OPERATOR_ADL_WKND(op) \
@@ -557,6 +558,7 @@ namespace detail
   LUABIND_OPERATOR_ADL_WKND(!=)
 
 #undef LUABIND_OPERATOR_ADL_WKND
+#endif
  
 } // namespace detail
 
