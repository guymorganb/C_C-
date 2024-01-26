#include <gpiod.h>
#include <stdio.h>
#include <nfc/nfc.h>
#include <usb.h>
#include <stdlib.h>
#include <sys/time.h>


    /* 
    lesson on pointers:
    -When a function needs to modify a value that should be accessible 
    outside the function, a pointer is used.
    -malloc is used to persist data outside the function scope
    -For values used only within the function, like your device_count in the modified function, a regular variable suffices. 
    It's a temporary value that doesn’t need to persist beyond the 
    function's execution
    // Pointer Example: detected.nmt = my_device->nm.nmt; This line copies the type (nmt) from the nfc_modulation structure inside my_device, pointed to by my_device, into the nmt field of your detected struct.
    */

nfc_modulation find_device(nfc_target ant[], int target_count, nfc_modulation detected){
    // Process detected targets in ant array
    for (int i = 0; i < target_count; i++) {
    // Process each detected tag based on its modulation type and baud rate
    // ant[i] contains information about each detected tag
        detected.nmt = ant[i].nm.nmt;
        detected.nbr = ant[i].nm.nbr;

    switch (ant[i].nm.nmt)
        {
        case NMT_ISO14443A:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_ISO14443A modulation type detected\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("ATQA: 0x%02x 0x%02x\n", ant[i].nti.nai.abtAtqa[0], ant[i].nti.nai.abtAtqa[1]);
            printf("SAK: 0x%02x\n", ant[i].nti.nai.btSak);
            printf("UID Length: %zu\n", ant[i].nti.nai.szUidLen);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("UID:");
            for (size_t j = 0; j < ant[i].nti.nai.szUidLen; j++) {
                printf(" 0x%02x", ant[i].nti.nai.abtUid[j]);
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_FELICA:
            detected.nmt = ant[i].nm.nmt;
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_FELICA modulation type detected\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("abtSysCode: 0x%02x 0x%02x\n", ant[i].nti.nfi.abtSysCode[0], ant[i].nti.nfi.abtSysCode[1]);
            printf("btResCode: 0x%02x\n", ant[i].nti.nfi.btResCode);
            printf("szLength: %zu\n", ant[i].nti.nfi.szLen);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("**ID & Pad:**");
            for (size_t j = 0; j < ant[i].nti.nfi.szLen; j++) {
                printf("ID: 0x%02x, Pad: 0x%02x\n", ant[i].nti.nfi.abtId[j], ant[i].nti.nfi.abtPad[j]);
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_JEWEL:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_JEWEL modulation type detected\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("btSensRes: 0x%02x 0x%02x\n", ant[i].nti.nji.btSensRes[0], ant[i].nti.nji.btSensRes[1]);
            printf("btId: 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nji.btId[0], ant[i].nti.nji.btId[1], ant[i].nti.nji.btId[2], ant[i].nti.nji.btId[3]);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_ISO14443B:
            printf("NMT_ISO14443B modulation type detected\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("ui8CardIdentifier: 0x%02x\n", ant[i].nti.nbi.ui8CardIdentifier);
            printf("abtPupi (btPupi store PUPI contained in ATQB (Answer To reQuest of type B)):\n 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nbi.abtPupi[0], ant[i].nti.nbi.abtPupi[1], ant[i].nti.nbi.abtPupi[2], ant[i].nti.nbi.abtPupi[3]);
            printf("abtApplicationData (abtApplicationData store Application Data contained in ATQB):\n 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nbi.abtApplicationData[0], ant[i].nti.nbi.abtApplicationData[1], ant[i].nti.nbi.abtApplicationData[2], ant[i].nti.nbi.abtApplicationData[3]);
            printf("abtProtocolInfo (ui8CardIdentifier store CID (Card Identifier) attributted by PCD to the PICC):\n 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nbi.abtProtocolInfo[0], ant[i].nti.nbi.abtProtocolInfo[1], ant[i].nti.nbi.abtProtocolInfo[2]);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_ISO14443BI:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_ISO14443BI modulation type detected (pre-ISO14443B aka ISO/IEC 14443 B' or Type B')\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("abtDIV(4 LSBytes of tag serial number):\n 0x%02x 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nii.abtDIV[0], ant[i].nti.nii.abtDIV[1], ant[i].nti.nii.abtDIV[2], ant[i].nti.nii.abtDIV[3]);
            printf("btVerLog(Software version & type of REPGEN):\n 0x%02x\n", ant[i].nti.nii.btVerLog);
            printf("btConfig(Config Byte, present if long REPGEN):\n 0x%02x\n", ant[i].nti.nii.btConfig);
            printf("AtrLen:\n %zu\n", ant[i].nti.nii.szAtrLen);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("**ATR, if any:**");
            for (size_t j = 0; j < ant[i].nti.nii.szAtrLen; j++) {
                printf("ID: 0x%02x\n", ant[i].nti.nii.abtAtr[j]);
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_ISO14443B2SR:
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_ISO14443B2SR modulation type detected (ISO14443-2B ST SRx)\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("abtUID:\n 0x%02x 0x%02x, 0x%02x, 0x%02x, 0x%02x 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nsi.abtUID[0], ant[i].nti.nsi.abtUID[1], ant[i].nti.nsi.abtUID[2], ant[i].nti.nsi.abtUID[3], ant[i].nti.nsi.abtUID[4], ant[i].nti.nsi.abtUID[5], ant[i].nti.nsi.abtUID[6], ant[i].nti.nsi.abtUID[7]);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_ISO14443B2CT:
        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_ISO14443B2CT modulation type detected (ISO14443-2B ASK CTx)\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("abtUID:\n 0x%02x 0x%02x, 0x%02x, 0x%02x\n", ant[i].nti.nci.abtUID[0], ant[i].nti.nci.abtUID[1], ant[i].nti.nci.abtUID[2], ant[i].nti.nci.abtUID[3]);
            printf("btProdCode:\n 0x%02x\n", ant[i].nti.nci.btProdCode);
            printf("btFabCode:\n 0x%02x\n", ant[i].nti.nci.btFabCode);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_DEP:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_DEP modulation type detected\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NFCID3:\n 0x%02x 0x%02x, 0x%02x, 0x%02x, 0x%02x 0x%02x, 0x%02x, 0x%02x, 0x%02x 0x%02x\n", ant[i].nti.ndi.abtNFCID3[0], ant[i].nti.ndi.abtNFCID3[1], ant[i].nti.ndi.abtNFCID3[2], ant[i].nti.ndi.abtNFCID3[3], ant[i].nti.ndi.abtNFCID3[4], ant[i].nti.ndi.abtNFCID3[5], ant[i].nti.ndi.abtNFCID3[6], ant[i].nti.ndi.abtNFCID3[7], ant[i].nti.ndi.abtNFCID3[8], ant[i].nti.ndi.abtNFCID3[9]);
            printf("btDID:\n 0x%02x\n", ant[i].nti.ndi.btDID);
            printf("Supported send-bit rate:\n 0x%02x\n", ant[i].nti.ndi.btBS);
            printf("Supported receive-bit rate :\n 0x%02x\n", ant[i].nti.ndi.btBR);
            printf("Timeout value:\n 0x%02x\n", ant[i].nti.ndi.btTO);
            printf("PP Parameters:\n 0x%02x\n", ant[i].nti.ndi.btPP);
            if(ant[i].nti.ndi.ndm == NDM_PASSIVE){
                printf("DEP mode: NDM_PASSIVE");
            }else if (ant[i].nti.ndi.ndm == NDM_ACTIVE)
            {
                printf("DEP mode: NDM_ACTIVE");
            }else{
                printf("DEP mode: NDM_UNDEFINED = 0");
            }
            printf("szGB:\n %zu\n", ant[i].nti.ndi.szGB);
            if(ant[i].nm.nbr == NBR_106){
                printf("Baud rate: NBR_106\n");
            }else if(ant[i].nm.nbr == NBR_212){
                printf("Baud rate: NBR_212\n");
            }else if(ant[i].nm.nbr == NBR_424){
                printf("Baud rate: NBR_424\n");
            }else if(ant[i].nm.nbr == NBR_847){
                printf("Baud rate: NBR_847\n");
            }else{
                printf("Baud rate: NBR_UNDEFINED\n");
            }
            printf("**General Bytes:**");
            for (size_t j = 0; j < ant[i].nti.ndi.szGB; j++) {
                printf("ID: 0x%02x\n", ant[i].nti.ndi.abtGB[j]);
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_BARCODE:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_BARCODE modulation type detected (Thinfilm NFC Barcode)\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("**szDataLen:**");
            for (size_t j = 0; j < ant[i].nti.nti.szDataLen; j++) {
                printf("ID: 0x%02x\n", ant[i].nti.nti.abtData[j]);
            }
            printf("\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            break;
        case NMT_ISO14443BICLASS:
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("NMT_ISO14443BICLASS modulation type detected (HID iClass 14443B mode)\n");
            printf("^^^^^^^^^^^^^No other data^^^^^^^^^^^^^^\n");
            break;
        default:
            break;
        }
        return detected;
    }
}

nfc_modulation get_nfc_target(nfc_device *my_device){

    bool breakLoop = false;
    // nfc_modulation detected; This line creates an instance of the nfc_modulation struct and we set default values.
    nfc_modulation mod_to_search_for = {0};
    nfc_baud_rate baudRates[] = {NBR_UNDEFINED, NBR_106, NBR_212, NBR_424, NBR_847};
    int numBaudRates = sizeof(baudRates) / sizeof(baudRates[0]);

    nfc_target ant[10]; // Array to store detected targets, adjust size as needed
    size_t szTargets = sizeof(ant) / sizeof(ant[0]);    // getthe size of the array
    
    // to-do make this loop run for 10 seconds even if a device is not found
    for (nfc_modulation_type type = NMT_ISO14443A; type <= NMT_END_ENUM; ++type) {
        for (int i = 0; i < numBaudRates; ++i) {
            mod_to_search_for.nmt = type;
            mod_to_search_for.nbr = baudRates[i];
            // passive targets are sensed tags, 
            // if a device is found, its filled into the ant[] and return to target_count
            int target_count = nfc_initiator_list_passive_targets(my_device, mod_to_search_for, ant, szTargets);
            printf("target count: %d\n", target_count);
            if (target_count > 0) {
                mod_to_search_for = find_device(ant, target_count, mod_to_search_for);
                
                if(mod_to_search_for.nmt == type){
                    printf("targets match!\n");
                    breakLoop = true;
                    break;
                }
            } else {
                perror("No targets found in nfc_get_target");
            }
        }
        if(breakLoop == true){  
            break;
        }
    }
    return mod_to_search_for;
}

struct nfc_context *nfc_initialize_libnfc(nfc_context **context) {
    
    uint8_t buffer[255];
    nfc_init(context);
    if (*context == NULL) {
        // Initialization failed
        return NULL;
    }
    return *context;
}

int main() {
    // getthe time
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    long long startMilliseconds = tv_start.tv_sec * 1000LL + tv_start.tv_usec / 1000;
    
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    long long nowMilliseconds = tv_now.tv_sec * 1000LL + tv_now.tv_usec / 1000;

    // initialize the context, this is libnfc.conf
    typedef const char *connection_string_t;    // create a type for the connection string
    connection_string_t connection_string = "pn532_i2c:/dev/i2c-1";   
    struct nfc_context *context = NULL;
    nfc_device *device; 
    nfc_modulation detected_device;
    bool device_found = false;

    
    // listen for button press
    // if button press intialize device
    // initialize the sequence open- >find_device_type-> set_device_type -> poll_device -> transceive -> save_data -> print_data -> close 


    // initialize the library: pass the contex, and run a loop searching for all supported devices for 10 sec
    while(nowMilliseconds - startMilliseconds < 10000){
        // Update the current time
        gettimeofday(&tv_now, NULL);
        nowMilliseconds = tv_now.tv_sec * 1000LL + tv_now.tv_usec / 1000;
        context = nfc_initialize_libnfc(&context);
        if (context == NULL) {
            fprintf(stderr, "Error initializing NFC context\n");
            return 1;
        }


        device = nfc_open(context, connection_string);
        if(device == NULL){
            fprintf(stderr, "Error initializing NFC device\n");
        }
        
        // get passive targets 
        detected_device = get_nfc_target(device);
        
        printf("Your modulation type: %d\n", detected_device.nmt);

        // try and print the detected device and recompile
        if(detected_device.nmt == NMT_ISO14443A){
        // modulation type is ISO14443A
        // set this type on ypur reader
        }else if(detected_device.nmt == NMT_JEWEL){
        // modulation type is ISO14443A
        // set this type on ypur reader
        }else{
            printf("inside else");
        }
        nfc_exit(context);
    }
    printf("Your context: %p\n", &context);
    printf("Your device: %p\n", device);
    
  
    return 0;
}



/// code for interacting with gpio pins:

  // const char *path;
    // struct gpiod_chip_info *chip_info;
    // struct gpiod_chip *chip;
    // struct gpiod_line_info *line_info;
    // struct gpiod_line_settings;
    // unsigned int line_num = 4;  // the line is also know as the offset

    // chip = gpiod_chip_open("/dev/gpiochip4");
    // if (!chip) {
    //     perror("gpiod chip not opened, no chip found");
    //     return 1;
    // }

    // // get the info from a specified line
    // line_info = gpiod_chip_get_line_info(chip, line_num);
    // if (!line_info) {
    //     perror("no line info to return, not line info found");
    //     return 1;
    // }

    // chip_info = gpiod_chip_get_info(chip);
    // if (!chip_info) {
    //     perror("no gpio info to return, not chip info found");
    //     gpiod_chip_close(chip);
    //     return 1;
    // }

    // path = gpiod_chip_get_path(chip);
    // if (!path) {
    //     perror("no gpio path found");
    //     gpiod_chip_close(chip);
    //     return 1;
    // }

    // printf("CHIP_INFO_FOR:%s\n", path);
    // printf("Line %d info:\n", line_num);
    // printf("Name: %s\n", gpiod_line_info_get_name(line_info));
    // printf("Consumer: %s\n", gpiod_line_info_get_consumer(line_info));
    // printf("Direction: %s\n", gpiod_line_info_get_direction(line_info) == GPIOD_LINE_DIRECTION_INPUT ? "Input" : "Output");
    // printf("chip name: %s\n", gpiod_chip_info_get_name(chip_info));

    // // Free the line info object
    // gpiod_line_info_free(line_info);

    // // The line is now configured as an input. Add any additional logic as needed.
    // gpiod_chip_close(chip);