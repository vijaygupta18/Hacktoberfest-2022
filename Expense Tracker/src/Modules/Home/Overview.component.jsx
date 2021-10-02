import React, { useEffect, useState } from "react";
import './Overview.css'

const AddTransactionView = (props) => {
  const [amount, setAmount] = useState();
  const [desc, setDesc] = useState();
  const [type, setType] = useState("EXPENSE");

  return (
    <div className="add-transaction-container" isAddTxnVisible={props.isAddTxnVisible}>
      <input
        placeholder="Amount"
        type="number"
        value={amount}
        onChange={(e) => setAmount(e.target.value)}
        
      />
      <input
        placeholder="Description"
        value={desc}
        onChange={(e) => setDesc(e.target.value)}
      />
      <div className="radio-box">
        <input
          type="radio"
          id="expense"
          name="type"
          value="EXPENSE"
          checked={type === "EXPENSE"}
          onChange={(e) => setType(e.target.value)}
        />
        <label htmlFor="expense">Expense</label>
        <input
          type="radio"
          id="income"
          name="type"
          value="INCOME"
          checked={type === "INCOME"}
          onChange={(e) => setType(e.target.value)}
        />
        <label htmlFor="Expense">Income</label>
      </div>

      <div className="add-transaction"
        onClick={() =>
          props.addTransaction({
            id: Date.now(),
            amount: Number(amount),
            desc,
            type,
          })
        }
      >
        Add Transaction
      </div>
    </div>
  );
};
const OverViewComponent = (props) => {
  const [isAddTxnVisible, toggleAddTXn] = useState(false);
  return (
    <div className="o-container">
      <div className="balance-box">
        Balance: ${props.income - props.expense}
        <div className="add-transaction" onClick={() => toggleAddTXn((isVisible) => !isVisible)}>
          {isAddTxnVisible ? "CANCEL" : "ADD"}
        </div>
      </div>
      {isAddTxnVisible && (
        <AddTransactionView
          isAddTxnVisible={isAddTxnVisible}
          addTransaction={(payload) => {
            props.addTransaction(payload);
            toggleAddTXn((isVisible) => !isVisible);
          }}
        />
      )}
      <div className="expense-container">
        <div className="expense-box">
          Expense<span>${props.expense}</span>
        </div>
        <div className="expense-box" isIncome={true}>
          Income<span>${props.income}</span>
        </div>
      </div>
    </div>
  );
};
export default OverViewComponent;
