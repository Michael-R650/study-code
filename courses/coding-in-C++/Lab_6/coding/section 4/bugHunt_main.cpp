#include <iostream>
#include <memory>
#include <vector>
#include "bugHunt_vehicle.hpp"
#include "bugHunt_assistance_system.hpp"

int main()
{
    Vehicle ego_vehicle("Vector X1",0);

    auto p1 = std::make_shared<DistanceSensor>("front", 25.0);
    auto p2 = std::make_shared<DistanceSensor>("rear", 1.2);
    auto p3 = std::make_shared<DistanceSensor>("left", 0.8);
    auto p4 = std::make_shared<DistanceSensor>("right", 3.0);

    
    std::vector<std::unique_ptr<AssistanceFeature>> safe;
    auto emergency_brake = std::make_unique<EmergencyBrakeSystem>(10.0);
    auto lane_assist = std::make_unique<LaneKeepingAssist>(0.4, 5.0);
    auto cruise_control = std::make_unique<AdaptiveCruiseControl>(80.0,15.0);
   
    ParkingAssistant parking_assistant(1.5);

    parking_assistant.add_sensor(p1);
    parking_assistant.add_sensor(p2);
    parking_assistant.add_sensor(p3);
    parking_assistant.add_sensor(p4);

    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle.print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle.accelerate(50.0);
    ego_vehicle.print_status();

    std::cout << "--- Adaptive cruise control test ---\n";
    p1->set_distance(12.0);
    cruise_control->evaluate(ego_vehicle, *p1);
    ego_vehicle.print_status();

    std::cout << "--- Emergency brake system test ---\n";
    p1->set_distance(25.0);
    emergency_brake->evaluate(ego_vehicle, *p1);
    ego_vehicle.print_status();

    std::cout << "--- Lane keeping assist test ---\n";
    ego_vehicle.update_lane_offset(0.7);
    lane_assist->evaluate(ego_vehicle);
    ego_vehicle.print_status();

    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();

    std::cout << "--- Manual braking test ---\n";
    ego_vehicle.brake(100.0);
    ego_vehicle.print_status();

    return 0;
}