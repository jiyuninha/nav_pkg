  
# 🚀 SCOUT 2.0 Navigation 


<br/><br/>

## **Prerequisites**
---
- LiDAR localization [**Fast Localization**](https://github.com/hwan0806/FAST-LOCALIZATION)
  - pcd data(submap) [**data**](https://drive.google.com/file/d/1uJNYgAl9EpmnVGMoPCPvhDYSY3XAQz-t/view?usp=sharing)
  
- [**scout package**](https://github.com/agilexrobotics/scout_ros)
- [**ugv_sdk**](https://github.com/westonrobot/ugv_sdk)

<br/><br/>

## **Updates**
---


<br/><br/>

## **Development Enviorment Setup**
---
- ROS noetic, ubuntu20.04

<br/>
<br/>

1. installation for scout 
```
mkdir scout_ws/src && cd scout_ws/src
catkin_init_workspace
git clone https://github.com/jiyuninha/nav_pkg.git
git clone https://github.com/westonrobot/ugv_sdk.git
git clone https://github.com/agilexrobotics/scout_ros.git
cd ~/scout_ws
catkin_make

```

2. installation for LiDAR localization
```
mkdir loc/src && cd loc/src
catkin_init_workspace
git clone https://github.com/ouster-lidar/ouster-ros.git
git clone https://github.com/hwan0806/FAST-LOCALIZATION.git
cd ~/loc 
catkin_make
```

3. first terminar
```
cd ~/loc
source devel/setup.bash
roslaunch ouster-ros sensor.launch
```
4. second terminar
```
cd ~/loc 
source devel/setup.bash
roslaunch fast_localization localization_ouster64.launch
```
5. third terminar
```
cd ~/scout_ws 
source devel/setup.bash
roscd scour_bringup 
cd scripts 
./bringup_can2usb.bash
cd ..
cd launch 
roslaunch scout_robot_base.launch
```
5. fourth terminar
```
cd ~/scout_ws
source devel/setup.bash
roslaunch nav_pkg nav.launch
```

<br/><br/>

###**Usage for Object Segmentation**
[![Video Label]](https://youtu.be/myETR4duN9g)

