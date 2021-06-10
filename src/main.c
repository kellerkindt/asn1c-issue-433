#include <stdio.h>
#include <CPM.h>
#include "helper.h"

void main(void) {
    CPM_t *cpm = calloc(1, sizeof(CPM_t)); 
    cpm->header.protocolVersion = 1;
    cpm->header.messageID = 1;
    cpm->header.stationID = 1337;
    cpm->cpm.generationDeltaTime = 123;
    cpm->cpm.cpmParameters.managementContainer.stationType = 1;
    cpm->cpm.cpmParameters.managementContainer.perceivedObjectContainerSegmentInfo = NULL;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.latitude = 2;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.longitude = 3;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.positionConfidenceEllipse.semiMajorConfidence = 4;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.positionConfidenceEllipse.semiMinorConfidence = 5;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.positionConfidenceEllipse.semiMajorOrientation = 6;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.altitude.altitudeValue = 7;
    cpm->cpm.cpmParameters.managementContainer.referencePosition.altitude.altitudeConfidence = 15;
    cpm->cpm.cpmParameters.stationDataContainer = NULL;
    cpm->cpm.cpmParameters.sensorInformationContainer = NULL;
    cpm->cpm.cpmParameters.perceivedObjectContainer = NULL;
    cpm->cpm.cpmParameters.freeSpaceAddendumContainer = calloc(1, sizeof(FreeSpaceAddendumContainer_t));
    cpm->cpm.cpmParameters.numberOfPerceivedObjects = 42;
    cpm->cpm.cpmParameters.timeReference = NULL;

    FreeSpaceAddendum_t *fsa = calloc(1, sizeof(FreeSpaceAddendum_t));
    fsa->freeSpaceConfidence = 4;
    fsa->freeSpaceArea.present = FreeSpaceArea_PR_freeSpaceCircular;
    fsa->freeSpaceArea.choice.freeSpaceCircular.nodeCenterPoint = NULL;
    fsa->freeSpaceArea.choice.freeSpaceCircular.radius = 2;
    fsa->sensorIDList = NULL;
    fsa->shadowingApplies = NULL;
    asn_sequence_add(&(cpm->cpm.cpmParameters.freeSpaceAddendumContainer->list), fsa);

    BAIL("printing cpm", helper_print_cpm(cpm, stdout));
    BAIL("checking constraints", helper_check_cpm(cpm, stderr));
    BAIL("sending cpm", helper_send_cpm(cpm));

    helper_free_cpm(&cpm);
}
