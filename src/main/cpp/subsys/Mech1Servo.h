
//====================================================================================================================================================
// Copyright 2021 Lake Orion Robotics FIRST Team 302 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//====================================================================================================================================================

#pragma once



// C++ Includes
#include <memory>

// FRC includes

// Team 302 includes
#include <hw/DragonServo.h>
#include <subsys/interfaces/IMech1Servo.h>


// Third Party Includes


class Mech1Servo : public IMech1Servo
{
	public:
        /// @brief Create a generic mechanism wiht 1 servo 
        /// @param [in] std::shared_ptr<DragonServo> servo used by this mechanism
        Mech1Servo
        (
            MechanismTypes::MECHANISM_TYPE              type,
            std::string                                 controlFileName,
            std::string                                 networkTableName,
            DragonServo*                                servo
        );
	    Mech1Servo() = delete;
	    virtual ~Mech1Servo() = default;

        /// @brief          Indicates the type of mechanism this is
        /// @return         MechanismTypes::MECHANISM_TYPE
        MechanismTypes::MECHANISM_TYPE GetType() const override;

        /// @brief indicate the file used to get the control parameters from
        /// @return std::string the name of the file 
        std::string GetControlFileName() const override;

        /// @brief indicate the Network Table name used to setting tracking parameters
        /// @return std::string the name of the network table 
        std::string GetNetworkTableName() const override;


        /// @brief log data to the network table if it is activated and time period has past
        void LogData() override;

        /// @brief      Move servo to the desired angle
        /// @param [in] double angle: Target angle in degrees
        /// @return     void
        void SetAngle
        (
            double angle       
        ) override;


    private:
        DragonServo*                                m_servo;
        MechanismTypes::MECHANISM_TYPE              m_type;
        std::string                                 m_controlFile;
        std::string                                 m_ntName;
        bool                                        m_logging;

};



