-- Simple calculator in Lua

-- Function to add two numbers
function add(x, y)
    return x + y
end

-- Function to subtract two numbers
function subtract(x, y)
    return x - y
end

-- Function to multiply two numbers
function multiply(x, y)
    return x * y
end

-- Function to divide two numbers
function divide(x, y)
    if y ~= 0 then
        return x / y
    else
        print("Cannot divide by zero.")
        os.exit(1)
    end
end

-- Main function
function main()
    if #arg ~= 3 then
        print("Usage: lua calculator.lua <number> <operator> <number>")
        os.exit(1)
    end

    local num1 = tonumber(arg[1])
    local operator = arg[2]
    local num2 = tonumber(arg[3])

    if num1 == nil or num2 == nil then
        print("Invalid input. Please provide valid numbers.")
        os.exit(1)
    end

    local result

    if operator == "+" then
        result = add(num1, num2)
    elseif operator == "-" then
        result = subtract(num1, num2)
    elseif operator == "*" then
        result = multiply(num1, num2)
    elseif operator == "/" then
        result = divide(num1, num2)
    else
        print("Invalid operator. Use +, -, *, or /.")
        os.exit(1)
    end

    print(string.format("%s %s %s = %s", num1, operator, num2, result))
end

-- Run the main function
main()

