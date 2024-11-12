// AUTOGENERATED FILE
#pragma once

#include "barretenberg/relations/relation_parameters.hpp"
#include "barretenberg/relations/relation_types.hpp"

namespace bb::Avm_vm {

template <typename FF_> class gasImpl {
  public:
    using FF = FF_;

    static constexpr std::array<size_t, 12> SUBRELATION_PARTIAL_LENGTHS = { 3, 3, 3, 3, 3, 3, 5, 5, 4, 4, 2, 2 };

    template <typename ContainerOverSubrelations, typename AllEntities>
    void static accumulate(ContainerOverSubrelations& evals,
                           const AllEntities& new_term,
                           [[maybe_unused]] const RelationParameters<FF>&,
                           [[maybe_unused]] const FF& scaling_factor)
    {

        {
            using Accumulator = typename std::tuple_element_t<0, ContainerOverSubrelations>;
            auto tmp = (new_term.main_is_gas_accounted -
                        ((FF(1) - new_term.main_is_fake_row) * new_term.main_sel_execution_row));
            tmp *= scaling_factor;
            std::get<0>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<1, ContainerOverSubrelations>;
            auto tmp = (new_term.main_l2_out_of_gas * (FF(1) - new_term.main_l2_out_of_gas));
            tmp *= scaling_factor;
            std::get<1>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<2, ContainerOverSubrelations>;
            auto tmp = (new_term.main_da_out_of_gas * (FF(1) - new_term.main_da_out_of_gas));
            tmp *= scaling_factor;
            std::get<2>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<3, ContainerOverSubrelations>;
            auto tmp = (new_term.main_is_fake_row * (FF(1) - new_term.main_is_fake_row));
            tmp *= scaling_factor;
            std::get<3>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<4, ContainerOverSubrelations>;
            auto tmp =
                (new_term.main_is_fake_row * (new_term.main_l2_gas_remaining - new_term.main_l2_gas_remaining_shift));
            tmp *= scaling_factor;
            std::get<4>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<5, ContainerOverSubrelations>;
            auto tmp =
                (new_term.main_is_fake_row * (new_term.main_da_gas_remaining - new_term.main_da_gas_remaining_shift));
            tmp *= scaling_factor;
            std::get<5>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<6, ContainerOverSubrelations>;
            auto tmp = ((new_term.main_is_gas_accounted *
                         ((FF(1) - new_term.main_sel_op_external_call) - new_term.main_sel_op_static_call)) *
                        (((new_term.main_l2_gas_remaining_shift - new_term.main_l2_gas_remaining) +
                          new_term.main_base_l2_gas_op_cost) +
                         (new_term.main_dyn_l2_gas_op_cost * new_term.main_dyn_gas_multiplier)));
            tmp *= scaling_factor;
            std::get<6>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<7, ContainerOverSubrelations>;
            auto tmp = ((new_term.main_is_gas_accounted *
                         ((FF(1) - new_term.main_sel_op_external_call) - new_term.main_sel_op_static_call)) *
                        (((new_term.main_da_gas_remaining_shift - new_term.main_da_gas_remaining) +
                          new_term.main_base_da_gas_op_cost) +
                         (new_term.main_dyn_da_gas_op_cost * new_term.main_dyn_gas_multiplier)));
            tmp *= scaling_factor;
            std::get<7>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<8, ContainerOverSubrelations>;
            auto tmp = (new_term.main_is_gas_accounted *
                        (((FF(1) - (FF(2) * new_term.main_l2_out_of_gas)) * new_term.main_l2_gas_remaining_shift) -
                         new_term.main_abs_l2_rem_gas));
            tmp *= scaling_factor;
            std::get<8>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<9, ContainerOverSubrelations>;
            auto tmp = (new_term.main_is_gas_accounted *
                        (((FF(1) - (FF(2) * new_term.main_da_out_of_gas)) * new_term.main_da_gas_remaining_shift) -
                         new_term.main_abs_da_rem_gas));
            tmp *= scaling_factor;
            std::get<9>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<10, ContainerOverSubrelations>;
            auto tmp = (new_term.main_abs_l2_rem_gas -
                        (new_term.main_l2_gas_u16_r0 + (new_term.main_l2_gas_u16_r1 * FF(65536))));
            tmp *= scaling_factor;
            std::get<10>(evals) += typename Accumulator::View(tmp);
        }
        {
            using Accumulator = typename std::tuple_element_t<11, ContainerOverSubrelations>;
            auto tmp = (new_term.main_abs_da_rem_gas -
                        (new_term.main_da_gas_u16_r0 + (new_term.main_da_gas_u16_r1 * FF(65536))));
            tmp *= scaling_factor;
            std::get<11>(evals) += typename Accumulator::View(tmp);
        }
    }
};

template <typename FF> class gas : public Relation<gasImpl<FF>> {
  public:
    static constexpr const char* NAME = "gas";

    static std::string get_subrelation_label(size_t index)
    {
        switch (index) {
        case 0:
            return "IS_GAS_ACCOUNTED";
        case 4:
            return "L2_GAS_NO_DECREMENT_FAKE_ROW";
        case 5:
            return "DA_GAS_NO_DECREMENT_FAKE_ROW";
        case 6:
            return "L2_GAS_REMAINING_DECREMENT_NOT_CALL";
        case 7:
            return "DA_GAS_REMAINING_DECREMENT_NOT_CALL";
        }
        return std::to_string(index);
    }
};

} // namespace bb::Avm_vm