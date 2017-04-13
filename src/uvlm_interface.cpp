#include "cpp_interface.h"
#define DLLEXPORT extern "C"

DLLEXPORT void run_VLM
(
    int& n_surf,
    int** dimensions_in,
    double** zeta_in
    // double** u_ext,
    // double** zeta_star,
    // double** gamma,
    // double** gamma_star,
    // UVLM::Types::VMopts& VMOPTS
)
{
    UVLM::Types::VecDimensions dimensions;
    UVLM::CppInterface::transform_dimensions(n_surf,
                                             dimensions_in,
                                             dimensions);

    UVLM::Types::VecVecMapX zeta;
    UVLM::CppInterface::map_VecVecMat(dimensions,
                                      zeta_in,
                                      zeta);

    std::cout << zeta[0][0] << std::endl;
    std::cout << zeta[0][1] << std::endl;
    std::cout << zeta[0][2] << std::endl;
}
