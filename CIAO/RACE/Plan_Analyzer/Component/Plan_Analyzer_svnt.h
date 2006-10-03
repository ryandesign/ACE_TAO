// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_GLUE_SESSION_PLAN_ANALYZER_SVNT_H
#define CIAO_GLUE_SESSION_PLAN_ANALYZER_SVNT_H

#include /**/ "ace/pre.h"

#include "Plan_AnalyzerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "Plan_AnalyzerS.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  class PlanIngress_Servant_T
  : public virtual POA_CIAO::RACE::PlanIngress
  {
    public:
    PlanIngress_Servant_T (
      ::CIAO::RACE::CCM_PlanIngress_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~PlanIngress_Servant_T (void);

    virtual void
    analyze_plan (
      const ::CIAO::RACE::Plan_Actions & foo
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CIAO::RACE::CCM_PlanIngress_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef PlanIngress_Servant_T<int> PlanIngress_Servant;
}

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Plan_Analyzer_Impl
    {
      class Plan_Analyzer_Servant;

      class PLAN_ANALYZER_SVNT_Export Plan_Analyzer_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_Plan_Analyzer_Context,
            Plan_Analyzer_Servant,
            ::CIAO::RACE::Plan_Analyzer,
            ::CIAO::RACE::Plan_Analyzer_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class Plan_Analyzer_Servant;

        Plan_Analyzer_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          Plan_Analyzer_Servant *sv);

        virtual ~Plan_Analyzer_Context (void);

        // Operations for Plan_Analyzer receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_Plan_Analyzer_Context.

        virtual ::CIAO::RACE::Planner_Manager_I_ptr
        get_connection_planner_manager_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual ::CIAO::RACE::Plan_Analyzer::pluginsConnections *
        get_connections_plugins (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO-specific.

        static Plan_Analyzer_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        virtual void
        connect_planner_manager_i (
          ::CIAO::RACE::Planner_Manager_I_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Planner_Manager_I_ptr
        disconnect_planner_manager_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::Components::Cookie *
        connect_plugins (
          ::CIAO::RACE::Analyzer_I_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Analyzer_I_ptr
        disconnect_plugins (
          ::Components::Cookie * ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidConnection));

        protected:
        // Simplex planner_manager_i connection.
        ::CIAO::RACE::Planner_Manager_I_var
        ciao_uses_planner_manager_i_;

        // Multiplex plugins connection.
        ACE_Active_Map_Manager<
        ::CIAO::RACE::Analyzer_I_var>
        ciao_uses_plugins_;
      };

      class PLAN_ANALYZER_SVNT_Export Plan_Analyzer_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::Plan_Analyzer,
            ::CIAO::RACE::CCM_Plan_Analyzer,
            Plan_Analyzer_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_Plan_Analyzer _exec_type;

        Plan_Analyzer_Servant (
          ::CIAO::RACE::CCM_Plan_Analyzer_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~Plan_Analyzer_Servant (void);

        virtual void
        set_attributes (
          const ::Components::ConfigValues &descr
          ACE_ENV_ARG_DECL);

        // Supported operations.

        // Public port operations.

        virtual ::CIAO::RACE::PlanIngress_ptr
        provide_plan_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual void
        connect_planner_manager_i (
          ::CIAO::RACE::Planner_Manager_I_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Planner_Manager_I_ptr
        disconnect_planner_manager_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::CIAO::RACE::Planner_Manager_I_ptr
        get_connection_planner_manager_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual ::Components::Cookie *
        connect_plugins (
          ::CIAO::RACE::Analyzer_I_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Analyzer_I_ptr
        disconnect_plugins (
          ::Components::Cookie * ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Plan_Analyzer::pluginsConnections *
        get_connections_plugins (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Component attribute operations.

        virtual ::CIAO::RACE::RACE_Classifications *
        classes (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Operations for Receptacles interface.

        virtual ::Components::Cookie *
        connect (
          const char *name,
          CORBA::Object_ptr connection
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::AlreadyConnected,
                         ::Components::ExceededConnectionLimit));

        virtual CORBA::Object_ptr
        disconnect (
          const char *name,
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::CookieRequired,
                         ::Components::NoConnection));

        virtual ::Components::ReceptacleDescriptions *
        get_all_receptacles (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Operations for Events interface.

        virtual ::Components::Cookie *
        subscribe (
          const char *publisher_name,
          ::Components::EventConsumerBase_ptr subscriber
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::ExceededConnectionLimit));

        virtual ::Components::EventConsumerBase_ptr
        unsubscribe (
          const char *publisher_name,
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection));

        virtual void
        connect_consumer (
          const char *emitter_name,
          ::Components::EventConsumerBase_ptr consumer
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::Components::EventConsumerBase_ptr
        disconnect_consumer (
          const char *source_name
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::NoConnection));

        virtual ::Components::PublisherDescriptions *
        get_all_publishers (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual ::Components::EmitterDescriptions *
        get_all_emitters (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO specific operations on the servant. 
        CORBA::Object_ptr
        get_facet_executor (
          const char *name
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        private:

        ::CIAO::RACE::PlanIngress_var
        provide_plan_ingress_;

        const char *ins_name_;

        private:

        void
        populate_port_tables (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        ::CORBA::Object_ptr
        provide_plan_ingress_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));
      };

      class PLAN_ANALYZER_SVNT_Export Plan_Analyzer_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::Plan_Analyzer_Home,
                ::CIAO::RACE::CCM_Plan_Analyzer_Home,
                Plan_Analyzer_Servant
              >
      {
        public:

        Plan_Analyzer_Home_Servant (
          ::CIAO::RACE::CCM_Plan_Analyzer_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~Plan_Analyzer_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };

      extern "C" PLAN_ANALYZER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_Plan_Analyzer_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        ::CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_PLAN_ANALYZER_SVNT_H */

