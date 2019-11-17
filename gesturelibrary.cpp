#include "gesturelibrary.h"

GestureLibrary *p_instance = 0;

GestureLibrary::GestureLibrary()
{

    landmarks_to_shm::gesture ges;

    boost::interprocess::managed_shared_memory segment(
        boost::interprocess::open_or_create,
        landmarks_datatype::shm_name,
        landmarks_datatype::shm_size);

    landmarks_datatype::coordinate3d_t *_bbCentral_ptr = segment.find<landmarks_datatype::coordinate3d_t>(
        landmarks_datatype::bbCentral_name).first;

}

GestureLibrary *GestureLibrary::instance(){
    if(!p_instance) p_instance = new GestureLibrary();
    return p_instance;
}

int GestureLibrary::GetgestureID(){

    int gestureID = (int)_bbCentral_ptr[1].z;
    return gestureID;
}



