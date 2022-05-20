#include "header.h"

namespace cahd
{
    Room::Room(std::string const& name, Size2D const& floor_area,
        SizeUnit room_height, FloorMaterial floor, WallMaterial const& wall)
    {
        m_name = name;
        m_floor_size = floor_area;
        m_room_height = room_height;
        m_floor = floor;
        m_wall = wall;
    }

    std::string const& Room::name() const
    {
        return m_name;
    }

    Size2D const& Room::floorSize() const
    {
        return m_floor_size;
    }

    SizeUnit Room::roomHeight() const
    {
        return m_room_height;
    }

    Room::FloorMaterial const& Room::floor() const
    {
        return m_floor;
    }

    Room::WallMaterial const& Room::wall() const
    {
        return m_wall;
    }

    namespace room
    {
        SizeUnit  computeVolume(Room const& room)
        {
            return room.roomHeight() * room.floorSize().first 
                * room.floorSize().second;
        }

        SizeUnit  computeFloorPerimiter(Room const& room)
        {
            return (room.floorSize().first +
                room.floorSize().second) * 2;
        }

        SizeUnit  computeFloorArea(Room const& room)
        {
            return room.floorSize().first
                * room.floorSize().second;
        }

        SizeUnit  computeWallArea(Room const& room)
        {
            return ((room.roomHeight() * room.floorSize().first)
                + (room.roomHeight() * room.floorSize().second))*2;
        }

        PriceUnit computeFloorPrice(Room const& room)
        {
            std::shared_ptr<Material> sp = std::shared_ptr<Material>(room.floor());
            return sp->m_price * computeFloorArea(room);
        }

        PriceUnit computeWallPrice(Room const& room)
        {
            std::shared_ptr<Material> sp = std::shared_ptr<Material>(room.wall());
            return sp->m_price * computeWallArea(room);
        }

        PriceUnit computePrice(Room const& room)
        {
            return computeWallPrice(room) + computeFloorPrice(room);
        }

    }   // namespace room

    HouseDesigner::HouseDesigner(std::string name)
    {
       m_name = name;
    }

    bool HouseDesigner::addMaterial(std::string const& name, PriceUnit price)
    {
        if (m_materials.contains(name))
            return false;
        else
        { 
            Material newMaterial;
            newMaterial.m_name = name;
            newMaterial.m_price = price;
            std::shared_ptr<Material> w_floor_ptr = std::make_shared<Material>(newMaterial);
            m_materials.insert(std::make_pair(name, w_floor_ptr));
        }
        return true;
    }

    bool HouseDesigner::addRoom(std::string const& name, Size2D floor_size,
        SizeUnit wall_height, FloorMaterialName floor_material,
        WallMaterialName wall_material)
    {
        if (m_rooms.contains(name))
        {
            return false;
        }
        else
        { 
            if (m_materials.contains(floor_material) && (m_materials.contains(wall_material)))
            {
                MaterialPtr ptr_floor = m_materials.at(floor_material);
                std::shared_ptr<Material> ptr_wall = m_materials.at(wall_material);
                Room room(name, floor_size, wall_height, ptr_wall, ptr_floor);
                m_rooms.insert(std::make_pair(name, room));
            }
            else
                return false;
        }
        return true;
    }

    bool HouseDesigner::removeMaterial(std::string const& name)
    {
        if (m_materials.contains(name))
        {
            m_materials.erase(name);
            return true;
        }
        
        return false;
    }

    bool HouseDesigner::removeRoom(std::string const& name)
    {
        if (m_rooms.contains(name))
        {
            m_rooms.erase(name);
            return true;
        }

       return false;
    }

    std::string const& HouseDesigner::name() const
    {
        return m_name;
    }

    SizeUnit HouseDesigner::computeVolume() const
    {
        double result = 0.0;

        for (auto& [name, room] : m_rooms)
        { 
           result += room.roomHeight() *
               room.floorSize().first * room.floorSize().second;
        }
        
        return result;
    }

    SizeUnit HouseDesigner::computeFloorArea() const
    {
        double result = 0.0;

        for (auto& [name, room] : m_rooms)
        {
            result += room.floorSize().first * room.floorSize().second;
        }

        return result;
    }

    SizeUnit HouseDesigner::computeWallArea() const
    {
        double result = 0.0;

        for (auto& [name, room] : m_rooms)
        {
            result += ((room.roomHeight() * room.floorSize().second)
                + (room.roomHeight() * room.floorSize().first))*2;
        }

        return result;
    }

    SizeUnit HouseDesigner::computePrice() const
    {
        //get the price pr. sq. meter
        //get the total amout of sq. ft
        //multiply
        double total_cost = 0.0;

        for (auto& [name, mptr] : m_materials)
        { 
            total_cost +=  mptr->m_price * 
                computeWallArea()* computeFloorArea();
        }

        return total_cost;
    }

} // END namespace cahd
