#pragma once

#include <list>

/// <summary>
/// Struct that stores a Layer and a list of Exclusion layers.
/// This struct is intended for internal use.
/// 
/// Notes: This isn't intended to be a very complex Physics Layer system. Instead, it tries to prioritize ease-of-use without concerning too much on bit flags.
/// </summary>
struct PhysicsLayer
{
public:
    unsigned Layer;
    std::list<unsigned> ExclusionLayers;

    bool ExcludesLayer(unsigned layer)
    {
        for (unsigned excludedLayer : ExclusionLayers)
        {
            if (excludedLayer == layer)
                return true;
        }
        return false;
    }

    void AddExcludedLayer(unsigned layer)
    {
        for (unsigned excludedLayer : ExclusionLayers)
        {
            if (excludedLayer == layer)
                return;
        }

        ExclusionLayers.push_back(layer);
    }

    void RemoveExcludedLayer(unsigned layer)
    {
        ExclusionLayers.remove(layer);
    }
};

