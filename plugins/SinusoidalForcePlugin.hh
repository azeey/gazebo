/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_SINUSOIDAL_FORCE_PLUGIN_HH_
#define _GAZEBO_SINUSOIDAL_FORCE_PLUGIN_HH_

#include <string>
#include <vector>

#include <sdf/sdf.hh>
#include "gazebo/common/Plugin.hh"
#include "gazebo/physics/PhysicsTypes.hh"

namespace gazebo
{
  class ForceData
  {
    public: physics::JointPtr joint;
    public: double average;
    public: double amplitude;
    public: double period;
  };

  class GAZEBO_VISIBLE SinusoidalForcePlugin : public ModelPlugin
  {
    /// \brief Constructor.
    public: SinusoidalForcePlugin() = default;

    /// \brief Destructor
    public: ~SinusoidalForcePlugin() = default;

    // Documentation Inherited.
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

    // Documentation inherited
    public: virtual void Init();

    /// \brief Callback for World Update events.
    protected: virtual void OnUpdate();

    /// \brief Connection to World Update events.
    protected: event::ConnectionPtr updateConnection;

    /// \brief Parent model.
    private: physics::ModelPtr model;

    /// \brief Pointer to the world.
    private: physics::WorldPtr world;

    /// \brief SDF for this plugin.
    private: sdf::ElementPtr sdf;

    // \brief List of all joints and the forces which should be applied.
    private: std::vector<ForceData> dataList;
  };
}
#endif
