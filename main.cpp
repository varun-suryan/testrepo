    for(const auto &[id, fixedB] : _satelliteData->fixedTxBeams()){
        
        // Compute the input beam ID.
        int64_t inputBeam = fixedB->beamID();

        // Find if we have spectrum instances for the uplink groups.
        auto fnd = uplinkGroups.find(inputBeam);
        
        if(fnd == uplinkGroups.end()){
            // No active beam?
            LOGGER_DEBUG(logger) << "Unable to route capacity from " << inputBeam << "; no spectrum instances...";
            continue;
        }

        // Compute the spectrum instances that survive the payload route.
        std::vector<SpectrumInstance> outputGroup = computeTransfer(*rt, fnd->second, satState);

        qDebug() << "Converted " << fnd->second.size() << " uplink signals into " << outputGroup.size() << " downlink";
        
        // Blend with the output groups we're building.
        auto outFnd = downlinkAmpInputGroups.find(rt->outputBeamId);

        if(outFnd == downlinkAmpInputGroups.end()){
            // Stick this vector into the downlink groups.
            downlinkAmpInputGroups.insert_or_assign(rt->outputBeamId, outputGroup);
        }
        else{
            // Blend the spectrums together.
            for(const auto &si : outputGroup){
                outFnd->second.push_back(si);
            }
        }
    }
