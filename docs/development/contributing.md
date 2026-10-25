# Contributing to Open AXI Interconnect

## Welcome

Thank you for your interest in contributing to the Open AXI Interconnect project! This document provides guidelines and procedures for making contributions to ensure a smooth collaboration experience while maintaining project quality and consistency.

## Code of Conduct

### Our Pledge

We pledge to foster an open and welcoming environment where all participants feel valued and respected regardless of:
- Experience level
- Background or identity
- Technical expertise area
- Communication style

### Our Standards

Positive behavior includes:
- Using welcoming and inclusive language
- Being respectful of differing viewpoints
- Gracefully accepting constructive criticism
- Focusing on what is best for the community
- Showing empathy towards other community members

Unacceptable behavior includes:
- Use of sexualized language or imagery
- Personal or political attacks
- Public or private harassment
- Publishing others' private information without permission
- Other conduct inappropriate in a professional setting

## How to Contribute

### Ways to Contribute

You can contribute in several ways:

1. **Code Contributions**
   - Bug fixes
   - New features
   - Performance improvements
   - Code refactoring

2. **Documentation Improvements**
   - Clarifications and corrections
   - New tutorials or examples
   - Translation efforts
   - API documentation enhancement

3. **Issue Reporting**
   - Bug reports
   - Feature requests
   - Enhancement suggestions
   - Usability feedback

4. **Community Support**
   - Answering questions
   - Helping new users
   - Reviewing pull requests
   - Participating in discussions

### Getting Started

1. **Fork the Repository**
   - Navigate to the [Open AXI Interconnect repository](https://github.com/open-axi-interconnect/open-axi-interconnect)
   - Click the "Fork" button in the upper right corner
   - Clone your fork locally: `git clone https://github.com/YOUR_USERNAME/open-axi-interconnect.git`

2. **Set Up Development Environment**
   - Install required tools (refer to README.md)
   - Set up upstream remote: `git remote add upstream https://github.com/open-axi-interconnect/open-axi-interconnect.git`
   - Create a feature branch: `git checkout -b feature/your-feature-name`

3. **Make Your Changes**
   - Follow coding standards outlined below
   - Write/update tests as needed
   - Update documentation
   - Commit your changes with clear messages

4. **Test Your Changes**
   - Run the complete test suite: `cd sim && make`
   - Verify lint-free code: `cd sim && make lint`
   - Check assertion syntax: `cd sim && make lint-assertions`
   - Confirm coverage targets maintained

5. **Submit Your Contribution**
   - Push to your fork: `git push origin feature/your-feature-name`
   - Create a Pull Request on GitHub
   - Respond to review feedback promptly

## Pull Request Process

### Before Submitting

Ensure your pull request:
1. Follows the project's coding standards
2. Includes appropriate tests for new functionality
3. Updates documentation as needed
4. Passes all automated checks
5. Has clear, descriptive commit messages

### Pull Request Requirements

1. **Description**
   - Clearly explain the problem being solved
   - Describe the solution implemented
   - Include references to related issues
   - Detail any breaking changes

2. **Testing**
   - All existing tests pass
   - New functionality includes tests
   - Coverage metrics maintained or improved
   - Performance impact assessed if relevant

3. **Documentation**
   - Code comments updated
   - User documentation updated
   - API documentation updated if applicable
   - README changes if necessary

### Review Process

1. **Automated Checks**
   - Code linting passes
   - Tests execute successfully
   - Coverage thresholds maintained
   - Documentation builds correctly

2. **Manual Review**
   - Code quality assessment
   - Design appropriateness
   - Test adequacy
   - Documentation clarity

3. **Approval and Merge**
   - At least one maintainer approval required
   - All feedback addressed
   - CI/CD checks pass
   - Merge by maintainers only

## Coding Standards

### SystemVerilog Guidelines

1. **Formatting**
   ```
   // Good: Consistent indentation and spacing
   module example_module #(
       parameter WIDTH = 32
   )(
       input  logic             clk,
       input  logic             rst_n,
       input  logic [WIDTH-1:0] data_in,
       output logic [WIDTH-1:0] data_out
   );
   ```

2. **Naming Conventions**
   - Signals: `lower_snake_case`
   - Modules: `lower_snake_case`
   - Parameters: `UPPER_CASE`
   - Instances: `u_module_name`

3. **Documentation**
   - Header comment for each module
   - Inline comments for complex logic
   - Parameter explanations
   - Signal purpose descriptions

### Python Guidelines (Cocotb Tests)

1. **Function Naming**
   ```python
   # Good: Descriptive test names
   @cocotb.test()
   async def test_uart_transmit_character(dut):
   ```

2. **Code Structure**
   - Import statements at top
   - Constants grouped logically
   - Helper functions before test cases
   - Clear test case separation

3. **Error Handling**
   ```python
   # Good: Meaningful assertions
   assert data == expected_value, f"Expected {hex(expected_value)}, got {hex(data)}"
   ```

### Documentation Standards

1. **Markdown Formatting**
   - Use consistent heading levels
   - Proper code block formatting
   - Clear table structures
   - Appropriate emphasis (bold/italic)

2. **Content Quality**
   - Accurate technical information
   - Clear, concise language
   - Practical examples
   - Logical information flow

## Testing Guidelines

### Test Development

1. **New Functionality**
   - Create corresponding test cases
   - Cover normal and error conditions
   - Validate boundary cases
   - Ensure adequate coverage

2. **Existing Tests**
   - Maintain compatibility
   - Update when behavior changes
   - Extend rather than replace when possible
   - Preserve test case intent

### Coverage Requirements

Contributions should maintain or improve:
- Functional coverage: ≥95%
- Statement coverage: ≥90%
- Branch coverage: ≥90%
- Toggle coverage: ≥90%

## Documentation Guidelines

### Content Structure

1. **Introduction**
   - Clear purpose statement
   - Audience identification
   - Prerequisites listing

2. **Body**
   - Logical progression of concepts
   - Practical examples
   - Visual aids where helpful
   - Cross-references to related content

3. **Conclusion**
   - Summary of key points
   - Next steps or related topics
   - Feedback mechanisms

### Writing Style

1. **Clarity**
   - Use active voice
   - Define technical terms
   - Avoid ambiguous language
   - Provide context for examples

2. **Consistency**
   - Follow established patterns
   - Maintain terminology consistency
   - Uniform formatting application
   - Standardized heading structure

## Issue Reporting

### Creating Effective Issues

When reporting bugs or requesting features:

1. **Bug Reports**
   - Clear, descriptive title
   - Steps to reproduce
   - Expected vs. actual behavior
   - Environment details
   - Relevant logs or error messages

2. **Feature Requests**
   - Problem statement
   - Proposed solution
   - Use cases and benefits
   - Alternatives considered

3. **Enhancement Suggestions**
   - Current limitation description
   - Improvement proposal
   - Impact assessment
   - Implementation considerations

## Community Engagement

### Communication Channels

1. **GitHub Issues**
   - Bug reports and feature requests
   - Technical discussions
   - Task tracking

2. **GitHub Discussions**
   - General conversation
   - Best practices sharing
   - Help and support requests
   - Project direction discussions

3. **Pull Request Reviews**
   - Code feedback
   - Design discussions
   - Implementation suggestions

### Recognition and Credit

Contributors are recognized through:
- GitHub contributor list
- Release notes mentions
- Documentation credits
- Community acknowledgments

## Maintainer Responsibilities

### Review Process

Maintainers commit to:
- Prompt initial response to contributions
- Constructive, respectful feedback
- Clear explanation of requested changes
- Timely final disposition of pull requests

### Quality Assurance

Maintainers ensure:
- Consistent application of standards
- Adequate testing coverage
- Documentation completeness
- Backward compatibility preservation

## Recognition Policy

### Contributor Acknowledgment

All contributors are acknowledged:
- In project documentation
- In release announcements
- Through GitHub contributor recognition
- In community communications

### Special Recognition

Significant contributions may receive:
- Featured contributor spotlights
- Speaking opportunities at events
- Project ambassador status
- Repository maintainer rights

## Conclusion

Contributing to the Open AXI Interconnect project is a collaborative effort aimed at creating high-quality, accessible hardware design resources. By following these guidelines, you help ensure a positive experience for all participants while advancing the project's goals.

Your contributions, whether large or small, are valuable to the community. Thank you for participating in this open-source endeavor and helping make hardware design more accessible to everyone.

If you have questions about contributing or need clarification on any aspect of this guide, please reach out through GitHub Issues or Discussions.