
#pragma once
#include "../../relation_parameters.hpp"
#include "../../relation_types.hpp"
#include "./declare_views.hpp"

namespace bb::Avm_vm {

template <typename FF> struct Avm_memRow {
    FF avm_mem_m_lastAccess{};
    FF avm_mem_m_op_b{};
    FF avm_mem_m_tag{};
    FF avm_mem_m_addr{};
    FF avm_mem_m_in_tag{};
    FF avm_mem_m_tag_shift{};
    FF avm_mem_m_last{};
    FF avm_mem_m_one_min_inv{};
    FF avm_mem_m_tag_err{};
    FF avm_mem_m_addr_shift{};
    FF avm_mem_m_sub_clk{};
    FF avm_mem_m_val_shift{};
    FF avm_mem_m_op_c{};
    FF avm_mem_m_val{};
    FF avm_mem_m_rw{};
    FF avm_mem_m_op_a{};
    FF avm_mem_m_rw_shift{};
};

inline std::string get_relation_label_avm_mem(int index)
{
    switch (index) {
    case 9:
        return "MEM_LAST_ACCESS_DELIMITER";

    case 10:
        return "MEM_READ_WRITE_VAL_CONSISTENCY";

    case 14:
        return "MEM_IN_TAG_CONSISTENCY_2";

    case 12:
        return "MEM_ZERO_INIT";

    case 11:
        return "MEM_READ_WRITE_TAG_CONSISTENCY";

    case 13:
        return "MEM_IN_TAG_CONSISTENCY_1";
    }
    return std::to_string(index);
}

template <typename FF_> class avm_memImpl {
  public:
    using FF = FF_;

    static constexpr std::array<size_t, 15> SUBRELATION_PARTIAL_LENGTHS{
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 3,
    };

    template <typename ContainerOverSubrelations, typename AllEntities>
    void static accumulate(ContainerOverSubrelations& evals,
                           const AllEntities& new_term,
                           [[maybe_unused]] const RelationParameters<FF>&,
                           [[maybe_unused]] const FF& scaling_factor)
    {

        // Contribution 0
        {
            Avm_DECLARE_VIEWS(0);

            auto tmp = (avm_mem_m_lastAccess * (-avm_mem_m_lastAccess + FF(1)));
            tmp *= scaling_factor;
            std::get<0>(evals) += tmp;
        }
        // Contribution 1
        {
            Avm_DECLARE_VIEWS(1);

            auto tmp = (avm_mem_m_last * (-avm_mem_m_last + FF(1)));
            tmp *= scaling_factor;
            std::get<1>(evals) += tmp;
        }
        // Contribution 2
        {
            Avm_DECLARE_VIEWS(2);

            auto tmp = (avm_mem_m_rw * (-avm_mem_m_rw + FF(1)));
            tmp *= scaling_factor;
            std::get<2>(evals) += tmp;
        }
        // Contribution 3
        {
            Avm_DECLARE_VIEWS(3);

            auto tmp = (avm_mem_m_tag_err * (-avm_mem_m_tag_err + FF(1)));
            tmp *= scaling_factor;
            std::get<3>(evals) += tmp;
        }
        // Contribution 4
        {
            Avm_DECLARE_VIEWS(4);

            auto tmp = (avm_mem_m_op_a * (-avm_mem_m_op_a + FF(1)));
            tmp *= scaling_factor;
            std::get<4>(evals) += tmp;
        }
        // Contribution 5
        {
            Avm_DECLARE_VIEWS(5);

            auto tmp = (avm_mem_m_op_b * (-avm_mem_m_op_b + FF(1)));
            tmp *= scaling_factor;
            std::get<5>(evals) += tmp;
        }
        // Contribution 6
        {
            Avm_DECLARE_VIEWS(6);

            auto tmp = (avm_mem_m_op_c * (-avm_mem_m_op_c + FF(1)));
            tmp *= scaling_factor;
            std::get<6>(evals) += tmp;
        }
        // Contribution 7
        {
            Avm_DECLARE_VIEWS(7);

            auto tmp = (avm_mem_m_sub_clk - (((avm_mem_m_rw * FF(3)) + avm_mem_m_op_b) + (avm_mem_m_op_c * FF(2))));
            tmp *= scaling_factor;
            std::get<7>(evals) += tmp;
        }
        // Contribution 8
        {
            Avm_DECLARE_VIEWS(8);

            auto tmp = (((avm_mem_m_op_a + avm_mem_m_op_b) + avm_mem_m_op_c) *
                        (((avm_mem_m_op_a + avm_mem_m_op_b) + avm_mem_m_op_c) - FF(1)));
            tmp *= scaling_factor;
            std::get<8>(evals) += tmp;
        }
        // Contribution 9
        {
            Avm_DECLARE_VIEWS(9);

            auto tmp = ((-avm_mem_m_lastAccess + FF(1)) * (avm_mem_m_addr_shift - avm_mem_m_addr));
            tmp *= scaling_factor;
            std::get<9>(evals) += tmp;
        }
        // Contribution 10
        {
            Avm_DECLARE_VIEWS(10);

            auto tmp = (((-avm_mem_m_lastAccess + FF(1)) * (-avm_mem_m_rw_shift + FF(1))) *
                        (avm_mem_m_val_shift - avm_mem_m_val));
            tmp *= scaling_factor;
            std::get<10>(evals) += tmp;
        }
        // Contribution 11
        {
            Avm_DECLARE_VIEWS(11);

            auto tmp = (((-avm_mem_m_lastAccess + FF(1)) * (-avm_mem_m_rw_shift + FF(1))) *
                        (avm_mem_m_tag_shift - avm_mem_m_tag));
            tmp *= scaling_factor;
            std::get<11>(evals) += tmp;
        }
        // Contribution 12
        {
            Avm_DECLARE_VIEWS(12);

            auto tmp = ((avm_mem_m_lastAccess * (-avm_mem_m_rw_shift + FF(1))) * avm_mem_m_val_shift);
            tmp *= scaling_factor;
            std::get<12>(evals) += tmp;
        }
        // Contribution 13
        {
            Avm_DECLARE_VIEWS(13);

            auto tmp = (((avm_mem_m_in_tag - avm_mem_m_tag) * (-avm_mem_m_one_min_inv + FF(1))) - avm_mem_m_tag_err);
            tmp *= scaling_factor;
            std::get<13>(evals) += tmp;
        }
        // Contribution 14
        {
            Avm_DECLARE_VIEWS(14);

            auto tmp = ((-avm_mem_m_tag_err + FF(1)) * avm_mem_m_one_min_inv);
            tmp *= scaling_factor;
            std::get<14>(evals) += tmp;
        }
    }
};

template <typename FF> using avm_mem = Relation<avm_memImpl<FF>>;

} // namespace bb::Avm_vm