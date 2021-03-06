#include "./utils/test_utils.hpp"
#include <string>
#include <vrm/pp/sep_to_str.hpp>
#include <vrm/pp/tpl.hpp>

int main()
{
    TEST_ASSERT(VRM_PP_TPL_ELEM((1, 2, 3), 0) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM((1, 2, 3), 1) == 2);
    TEST_ASSERT(VRM_PP_TPL_ELEM((1, 2, 3), 2) == 3);

    TEST_ASSERT(VRM_PP_TPL_ELEM(VRM_PP_TPL_MAKE(1, 2, 3), 0) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM(VRM_PP_TPL_MAKE(1, 2, 3), 1) == 2);
    TEST_ASSERT(VRM_PP_TPL_ELEM(VRM_PP_TPL_MAKE(1, 2, 3), 2) == 3);

    TEST_ASSERT(VRM_PP_TPL_ELEM(VRM_PP_TPL_EXPLODE(((1, 2))), 0) == 1);
    TEST_ASSERT(std::string{VRM_PP_SEP_TOSTR(
                    ", ", VRM_PP_TPL_EXPLODE((1, 2)))} == "1, 2");

#define TEST_MACRO_CONCATENATED_TPLS VRM_PP_TPL_CAT((1, 2), (3, 4))
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 0) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 1) == 2);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 2) == 3);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 3) == 4);
#undef TEST_MACRO_CONCATENATED_TPLS

    TEST_ASSERT(VRM_PP_TPL_ELEM(VRM_PP_TPL_CAT((1), (3)), 1) == 3);

#define TEST_MACRO_CONCATENATED_TPLS \
    VRM_PP_TPL_CAT((1), (1, 2), (3, 4), (4, 5, 6), (1))

    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 0) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 1) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 2) == 2);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 3) == 3);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 4) == 4);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 5) == 4);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 6) == 5);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 7) == 6);
    TEST_ASSERT(VRM_PP_TPL_ELEM(TEST_MACRO_CONCATENATED_TPLS, 8) == 1);

    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 0) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 1) == 6);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 2) == 5);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 3) == 4);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 4) == 4);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 5) == 3);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 6) == 2);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 7) == 1);
    TEST_ASSERT(VRM_PP_TPL_ELEM_REVERSE(TEST_MACRO_CONCATENATED_TPLS, 8) == 1);

#undef TEST_MACRO_CONCATENATED_TPLS

    return 0;
}